//
// Created by fbi168 on 18/05/24.
//
#include "gtest/gtest.h"
#include "../headerFiles/Register.h"

class RegisterFixture: public ::testing::Test{
protected:
    void SetUp() override{
        reg.addActivity(Activity ("Go to the cinema", Date(16, 8, 2024),
                                          Time(17, 30), Time(19, 30)));
        reg.addActivity(Activity ("Finish the register test", Date(16, 8, 2024),
                                  Time(20, 00), Time(21, 30)));
    }

    Register reg;
};

TEST_F(RegisterFixture, addActivityTest){
    reg.addActivity(Activity ("Do the dish washing", Date(16, 8, 2024),
                              Time(19, 30), Time(19, 50)));
    auto activity = reg.getActivitiesForDate("2024-8-16");
    ASSERT_EQ(activity[0].getDescription(), "Go to the cinema");
    ASSERT_EQ(activity[1].getDescription(), "Do the dish washing");
    ASSERT_EQ(activity[2].getDescription(), "Finish the register test");
    EXPECT_THROW(reg.addActivity(Activity ("Finish the unit testing of the activities register", Date(16, 8, 2024),
                              Time(19, 10), Time(19, 20))), std::invalid_argument);

}

TEST_F(RegisterFixture, deleteActivityTest){
    reg.deleteActivity("2024-8-16", 0);
    auto activity = reg.getActivitiesForDate("2024-8-16");
    ASSERT_EQ(activity[0].getDescription(), "Finish the register test");
    reg.deleteActivity("2024-8-16", 1);
    ASSERT_EQ(activity[0].getDescription(), "Finish the register test");
    reg.deleteActivity("2024-8-16", -1);
    ASSERT_EQ(activity[0].getDescription(), "Finish the register test");
}