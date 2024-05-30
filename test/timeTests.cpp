//
// Created by fbi168 on 25/05/24.
//
#include "gtest/gtest.h"
#include "../headerFiles/Time.h"

TEST(timeTest, constructorTest){
    Time time(23, 11);
    ASSERT_EQ(time.getHour(), 23);
    ASSERT_EQ(time.getMinute(), 11);
}

TEST(timeTest, defaultConstructorTest){
    Time time;
    ASSERT_EQ(time.getHour(), 0);
    ASSERT_EQ(time.getMinute(), 0);
}

TEST(timeTest, operatorEqualityTest){
    Time time1(23, 11);
    Time time2(23, 11);
    ASSERT_TRUE(time1 == time2);
    time1.setHour(22);
    ASSERT_FALSE(time1 == time2);
}

TEST(timeTest, invalidTimeTest){
    EXPECT_THROW(Time time(24, 11), std::out_of_range);
    EXPECT_THROW(Time time(-1, 11), std::out_of_range);
    EXPECT_THROW(Time time(23, -1), std::out_of_range);
    EXPECT_THROW(Time time(23, 60), std::out_of_range);
    EXPECT_THROW(Time time(24, 60), std::out_of_range);
}

TEST(timeTest, setterTimeTest){
    Time time(23, 11);
    EXPECT_THROW(time.setHour(24), std::out_of_range);
    EXPECT_THROW(time.setHour(-1), std::out_of_range);
    EXPECT_THROW(time.setMinute(60), std::out_of_range);
    EXPECT_THROW(time.setMinute(-1), std::out_of_range);
}