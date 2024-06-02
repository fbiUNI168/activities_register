//
// Created by fbi168 on 22/05/24.
//

#include "../headerFiles/Time.h"
#include <stdexcept>

Time::Time(int hour, int minute) {
    if(!validTime(hour, minute))
        throw std::out_of_range("Not a valid hour!");
    else{
        this->hour = hour;
        this->minute = minute;
    }
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
        return minute;
}

void Time::setHour(int hour) {
    if(validHour(hour))
        Time::hour = hour;
    else
        throw std::out_of_range("Not a valid hour!");
}

void Time::setMinute(int minute) {
    if(validMinute(minute))
        Time::minute = minute;
    else
        throw std::out_of_range("Not a valid minute!");
}

bool Time::validHour(int hour) const {
    if(hour >= 0 && hour <= 23)
        return true;
    return false;
}

bool Time::validMinute(int minute) const {
    if(minute >= 0 && minute <= 59)
        return true;
    return false;
}

bool Time::validTime(int hour, int minute) const {
    if(validHour(hour) && validMinute(minute))
        return true;
    return false;
}

bool Time::operator==(const Time &time) const{
    if(hour == time.hour && minute == time.minute)
        return true;
    return false;
}