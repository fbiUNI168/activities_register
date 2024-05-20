//
// Created by fbi168 on 17/05/24.
//

#include "Activity.h"
#include <stdexcept>

Activity::Activity(std::string description, std::tm startTime, std::tm endTime) {
    if(!isValidDatesRange(startTime, endTime))
        throw std::out_of_range("Not a valid date range for an activity!");

    this->description = description;
    this->startTime = startTime;
    this->endTime = endTime;
}

bool Activity::isValidDatesRange(const std::tm &date1, const std::tm &date2) const {
    if(isCoincidentDay(date1, date2) && isValidHours(date1, date2))
        return true;
    else
        return false;
}

bool Activity::isCoincidentDay(const std::tm &date1, const std::tm &date2) const {
    if(date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday == date2.tm_mday)
        return true;
    else
        return false;
}

bool Activity::isValidHours(const std::tm &date1, const std::tm &date2) const {
    if(date1.tm_hour < date2.tm_hour && date1.tm_min < date2.tm_min)
        return true;
    else
        return false;
}