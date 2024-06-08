//
// Created by fbi168 on 18/05/24.
//
#include "gtest/gtest.h"
#include "../headerFiles/Activity.h"

TEST(activityTest, constructorTest) {
    Activity activity("Do the project for programmation", Date(16, 8, 2024),
                      Time(17, 30), Time(18, 00));
    ASSERT_EQ(activity.getDate(), Date(16, 8, 2024));
    ASSERT_EQ(activity.getDescription(), "Do the project for programmation");
    ASSERT_EQ(activity.getStartTime(), Time(17, 30));
    ASSERT_EQ(activity.getEndTime(), Time(18, 00));

}

TEST(activityTest, invalidActivitytest){
    EXPECT_THROW( Activity activity("Do the project for programmation", Date(16, 8, 2024),
                          Time(18, 30), Time(18, 00)), std::out_of_range);
    EXPECT_THROW( Activity activity("Do the project for programmation", Date(16, 8, 2024),
                          Time(19, 00), Time(18, 00)), std::out_of_range);
    EXPECT_THROW( Activity activity("Do the project for programmation", Date(16, 8, 2024),
                          Time(18, 00), Time(18, 00)), std::out_of_range);

}

TEST(activityTest, settersTest){
    Activity activity("Do the project for programmation", Date(16, 8, 2024),
                      Time(17, 30), Time(18, 00));
    EXPECT_THROW(activity.setDate(Date(0, 1, 2024)), std::out_of_range);
    EXPECT_THROW(activity.setStartTime(Time(-1, 25)), std::out_of_range);
    EXPECT_THROW(activity.setStartTime(Time(16, 61)), std::out_of_range);
    EXPECT_THROW(activity.setEndTime(Time(-1, 25)), std::out_of_range);
    EXPECT_THROW(activity.setEndTime(Time(16, 61)), std::out_of_range);

}

TEST(activityTest, getParsedDateTest){
    Activity activity("Do the project for programmation", Date(16, 8, 2024),
                      Time(17, 30), Time(18, 00));
    ASSERT_EQ(activity.getParsedDate(), "2024-8-16");
}

TEST(ActivityTest, isOverlappingTest){
    Activity firstActivity("Do the project for programmation", Date(16, 8, 2024),
                      Time(17, 30), Time(18, 00));
    Activity secondActivity("Do the project for programmation", Date(16, 8, 2024),
                           Time(17, 15), Time(17, 45));
    EXPECT_TRUE(firstActivity.isOverlapping(secondActivity));
    secondActivity.setEndTime(Time(18, 15));
    secondActivity.setStartTime(Time(17, 45));
    EXPECT_TRUE(firstActivity.isOverlapping(secondActivity));
    secondActivity.setStartTime(Time(17, 35));
    secondActivity.setEndTime(Time(17, 55));
    EXPECT_TRUE(firstActivity.isOverlapping(secondActivity));
}