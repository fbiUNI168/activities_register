//
// Created by fbi168 on 17/05/24.
//

#include "../headerFiles/Activity.h"
#include <stdexcept>

Activity::Activity(const std::string& description, Date date, Time startTime, Time endTime) {
    if(!isValidDatesRange(startTime, endTime))
        throw std::out_of_range("Not a valid date range for an activity!");

    this->description = description;
    this->startTime = startTime;
    this->endTime = endTime;
}

void Activity::setDate(const Date &date) {
    Activity::date = date;
}

void Activity::setStartTime(const Time &startTime) {
    Activity::startTime = startTime;
}

void Activity::setEndTime(const Time &endTime) {
    Activity::endTime = endTime;
}

const Date &Activity::getDate() const {
    return date;
}

void Activity::setDescription(const std::string &description) {
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
    else if(startTime.getMinute() > endTime.getMinute())
        return false;
    else
        return true;
}

bool Activity::isOverlapping(const Activity& activity) {
    if((startTime.getHour() == activity.getEndTime().getHour() && startTime.getMinute() < activity.getEndTime().getMinute()) ||
            (endTime.getHour() == activity.getStartTime().getHour() && endTime.getMinute() > activity.getStartTime().getMinute()) ||
            startTime.getHour() < activity.getEndTime().getHour() && endTime.getHour() > activity.getStartTime().getHour())
        return true;
    return false;
}

std::string Activity::getParsedDate() const{
    std::string parsedDate = std::to_string(date.getYear()) + " " + std::to_string(date.getMonth()) + " " + std::to_string(date.getDay());
    return parsedDate;
}

