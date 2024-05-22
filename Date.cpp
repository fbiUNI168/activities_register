//
// Created by fbi168 on 18/05/24.
//

#include "Date.h"
#include <stdexcept>

enum{ JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL = 4, MAY = 5,
        JUNE = 6, JULY = 7, AUGUST = 8, SEPTEMBER = 9, OCTOBER = 10, NOVEMBER = 11, DECEMBER = 12};

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


int Date::getDaysOfMonth(const int& month, const int& year) const {
    switch (month) {
        case FEBRUARY:
            if (isLeap(year))
                return 29;
            else
                return 28;
        case APRIL:
            return 30;
        case JUNE:
            return 30;
        case SEPTEMBER:
            return 30;
        case NOVEMBER:
            return 30;
        default:
            return 31;
    }
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
