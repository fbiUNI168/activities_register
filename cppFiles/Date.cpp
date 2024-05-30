//
// Created by fbi168 on 18/05/24.
//

#include "../headerFiles/Date.h"
#include <stdexcept>

enum{ FEBRUARY = 2,APRIL = 4,
        JUNE = 6, SEPTEMBER = 9, NOVEMBER = 11};

Date::Date(int day, int month, int year) {
    if (!validDate(day, month, year))
        throw std::out_of_range("Date not valid!");
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    if (validDay(day, this->month, this->year))
        this->day = day;
    else
        throw std::out_of_range("Day not valid!");

}

void Date::setMonth(int month) {
    if (validMonth(month)) {
        if (validDay(this->day, month,
                     this->year))
            this->month = month;
        else
            throw std::out_of_range("Day not valid the selected month!");
    } else
        throw std::out_of_range("Month not valid!");

}

void Date::setYear(int year) {
    if (validYear(year)) {
        if (validDay(this->day, month, this->year))
            this->year = year;
        else
            throw std::out_of_range("Day not valid the selected year!");
    } else
        throw std::out_of_range("Year not valid!");
}

bool Date::isLeap(int year) const {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        } else
            return true;
    }
    return false;
}


int Date::getDaysOfMonth(int month,  int year) const {
    int numberOfDays = 31;
    switch (month) {
        case FEBRUARY:
            if (isLeap(year))
                numberOfDays =  29;
            else
                numberOfDays = 28;
        break;
        case APRIL:

        case JUNE:

        case SEPTEMBER:

        case NOVEMBER:
            numberOfDays = 30;
        break;
    }
    return numberOfDays;
}


bool Date::validDate(int day, int month, int year) {
    if (validDay(day, month, year) && validMonth(month) && validYear(year))
        return true;
    return false;
}

bool Date::operator==(const Date &date) const {
    if (this->day == date.day && this->month == date.month && this->year == date.year)
        return true;
    return false;
}

bool Date::validDay(int day, int month, int year) const {
    if (day > 0 && day <= getDaysOfMonth(month, year))
        return true;
    return false;
}

bool Date::validMonth(int month) {
    if (month > 0 && month < 13)
        return true;
    return false;
}

bool Date::validYear(int year) {
    if (year >= 2000 && year <= 2100)
        return true;
    return false;
}