//
// Created by fbi168 on 27/05/24.
//
#include "gtest/gtest.h"
#include "../headerFiles/Date.h"

TEST(dateTest, constructorTest){
    Date date(23, 11, 2024);
    ASSERT_EQ(date.getDay(), 23);
    ASSERT_EQ(date.getMonth(), 11);
    ASSERT_EQ(date.getYear(), 2024);
}

TEST(dateTest, defaultConstructorTest){
    Date date;
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getYear(), 1970);
}


TEST(DateTest, isLeapTest) {
    Date date(29, 2, 2024);
    ASSERT_EQ(date.getDay(), 29);
    Date date2(15, 2, 2023);
    EXPECT_THROW(date2.setDay(29), std::out_of_range);
}

TEST(DateTest, getDaysOfMonthTest) {
    Date date(15, 9, 2000);
    date.setDay(30);
    ASSERT_EQ(date.getDay(), 30);
    EXPECT_THROW(date.setMonth(2), std::out_of_range);
}

TEST(DateTest, equalityOperatorTest) {
    Date d1(16, 8, 2024);
    Date d2(16, 8, 2024);

    ASSERT_TRUE(d1 == d2);
    d2.setDay(11);
    ASSERT_FALSE(d1 == d2);
}

TEST(DateTest, invalidDateTest) {
    EXPECT_THROW(Date date(29, 2, 2023), std::out_of_range);
    EXPECT_THROW(Date date(31, 4, 2024), std::out_of_range);
    EXPECT_THROW(Date date(33, 6, 2024), std::out_of_range);
    EXPECT_THROW(Date date(0, 7, 2024), std::out_of_range);
    EXPECT_THROW(Date date(10, 0, 2024), std::out_of_range);
    EXPECT_THROW(Date date(10, 13, 2024), std::out_of_range);
}