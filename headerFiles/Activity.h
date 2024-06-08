//
// Created by fbi168 on 17/05/24.
//

#ifndef ACTIVITIES_REGISTER_ACTIVITY_H
#define ACTIVITIES_REGISTER_ACTIVITY_H
#include <string>
#include <chrono>
#include <ctime>
#include "Date.h"
#include "Time.h"
class Activity {
public:
    Activity(const std::string& description, Date date, Time startTime, Time endTime);

    const std::string &getDescription() const;

    const Time &getStartTime() const;

    const Time &getEndTime() const;

    const Date &getDate() const;

    void setDate(const Date &date);

    void setStartTime(const Time &startTime);

    void setEndTime(const Time &endTime);

    void setDescription(const std::string &description);

    std::string getParsedDate() const;

    bool isOverlapping(const Activity &comparisonActivity);

private:
    bool isValidDatesRange(const Time& startTime, const Time& endTime) const;

    std::string description;
    Date date;
    Time startTime;
    Time endTime;

};


#endif //ACTIVITIES_REGISTER_ACTIVITY_H
