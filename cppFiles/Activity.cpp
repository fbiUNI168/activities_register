//
// Created by fbi168 on 17/05/24.
//

#include "../headerFiles/Activity.h"
#include <stdexcept>

Activity::Activity(const std::string& description, Date date, Time startTime, Time endTime) {
    if(!isValidDatesRange(startTime, endTime))
        throw std::out_of_range("Not a valid date range for an activity!");

    if(description.empty()) {
        this->description = "Activity";
    }else{
        this->description = description;
    }
    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;
}

void Activity::setDate(const Date &date) {
    Activity::date = date;
}

void Activity::setStartTime(const Time &startTime) {
    if(isValidDatesRange(startTime, this->endTime))
        Activity::startTime = startTime;
    else
        throw std::invalid_argument("Invalid start time");
}

void Activity::setEndTime(const Time &endTime) {
    if(isValidDatesRange(this->startTime, endTime))
        Activity::endTime = endTime;
    else
        throw std::invalid_argument("End time");
}

const Date &Activity::getDate() const {
    return date;
}

void Activity::setDescription(const std::string &description) {
    if(!description.empty())
        this->description = description;
}

const std::string &Activity::getDescription() const {
    return description;
}

const Time &Activity::getStartTime() const {
    return startTime;
}

const Time &Activity::getEndTime() const {
    return endTime;
}

bool Activity::isValidDatesRange(const Time &startTime, const Time &endTime) const {
    if(startTime.getHour() > endTime.getHour())
        return false;
    else if(startTime == endTime)
        return false;
    else if( startTime.getHour() == endTime.getHour() && startTime.getMinute() > endTime.getMinute())
        return false;
    else
        return true;
}

bool Activity::isOverlapping(const Activity &comparisonActivity) {
        int thisStartMinutes = startTime.getHour() * 60 + startTime.getMinute();
        int thisEndMinutes = endTime.getHour() * 60 + endTime.getMinute();
        int comparisonStartMinutes = comparisonActivity.startTime.getHour() * 60 + comparisonActivity.startTime.getMinute();
        int comparisonEndMinutes = comparisonActivity.endTime.getHour() * 60 + comparisonActivity.endTime.getMinute();

        if(thisStartMinutes < comparisonEndMinutes && thisEndMinutes > comparisonStartMinutes)
            return true;
        else
            return false;
}