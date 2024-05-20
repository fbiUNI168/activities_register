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
    Activity(std::string description, std::tm startTime, std::tm endTime);

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
    bool isValidDatesRange(const std::tm& date1, const std::tm& date2) const;

    bool isCoincidentDay(const std::tm& date1, const std::tm& date2) const;

    bool isValidHours(const std::tm& date1, const std::tm& date2) const;

    std::string description;
    std::tm startTime;
    std::tm endTime;

};


#endif //ACTIVITIES_REGISTER_ACTIVITY_H
