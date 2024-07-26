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
    EXPECT_THROW(reg.addActivity(Activity ("Finish the unit testing of the activitiesTable register", Date(16, 8, 2024),
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

    reg.deleteActivity("2024-8-15", 0);
    ASSERT_EQ(activity[0].getDescription(), "Finish the register test");


}

TEST_F(RegisterFixture, deleteActivitiesTest){
    reg.deleteActivities("2024-8-16");
    auto activity = reg.getActivitiesForDate("2024-8-16");
    ASSERT_EQ(activity.size(), 0);
}

TEST_F(RegisterFixture, updateRegisterFormFileTest){
    std::string testFilePath = "../activitiesData/data.txt";
    std::ofstream fout(testFilePath);
    fout << "2024-07-25;08:30;10:00;Meeting with team\n";
    fout << "2024-07-26;09:00;11:00;Project discussion\n";
    fout.close();

    reg.updateRegisterFormFile();

    std::vector<Activity> activities = reg.getActivitiesForDate("2024-7-25");
    EXPECT_EQ(activities[0].getDescription(), "Meeting with team");
    EXPECT_EQ(activities[0].getStartTime().getHour(), 8);
    EXPECT_EQ(activities[0].getStartTime().getMinute(), 30);
    EXPECT_EQ(activities[0].getEndTime().getHour(), 10);
    EXPECT_EQ(activities[0].getEndTime().getMinute(), 0);
}

TEST_F(RegisterFixture, saveToFileTest){

    reg.addActivity(Activity ("Do the dish washing", Date(16, 8, 2024),
                              Time(19, 30), Time(19, 50)));
    reg.saveToFile();
    reg.deleteActivities("2024-8-16");

    reg.updateRegisterFormFile();

    std::vector<Activity> activities = reg.getActivitiesForDate("2024-8-16");
    EXPECT_EQ(activities[1].getDescription(), "Do the dish washing");
    EXPECT_EQ(activities[1].getStartTime().getHour(), 19);
    EXPECT_EQ(activities[1].getStartTime().getMinute(), 30);
    EXPECT_EQ(activities[1].getEndTime().getHour(), 19);
    EXPECT_EQ(activities[1].getEndTime().getMinute(), 50);

}