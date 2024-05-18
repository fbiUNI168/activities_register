//
// Created by fbi168 on 17/05/24.
//

#ifndef ACTIVITIES_REGISTER_ACTIVITY_H
#define ACTIVITIES_REGISTER_ACTIVITY_H
#include <string>
#include <chrono>
#include <ctime>

class Activity {
public:
    Activity(std::string description, std::tm startTime, std::tm endTime): description(description), startTime(startTime), endTime(endTime){}

    const std::string &getDescription() const {
        return description;
    }

    const tm &getStartTime() const {
        return startTime;
    }

    const tm &getEndTime() const {
        return endTime;
    }

    void setDescription(const std::string &description) {
        this->description = description;
    }

    void setStartTime(const tm &startTime) {
        this->startTime = startTime;
    }

    void setEndTime(const tm &endTime) {
        this->endTime = endTime;
    }

private:
    std::string description;
    std::tm startTime;
    std::tm endTime;

};


#endif //ACTIVITIES_REGISTER_ACTIVITY_H
