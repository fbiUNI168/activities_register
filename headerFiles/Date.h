//
// Created by fbi168 on 18/05/24.
//

#ifndef ACTIVITIES_REGISTER_DATE_H
#define ACTIVITIES_REGISTER_DATE_H
#include <string>

class Date {
public:
    Date(int day, int month, int year);

    Date() : Date(1, 1, 1970) {}

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    bool operator==(const Date &date) const;

    std::string getParsedDate() const;

private:
    int getDaysOfMonth(int month, int year) const;

    bool isLeap(int year) const;

    bool validDate(int day, int month, int year);

    int day;
    int month;
    int year;
};


#endif //ACTIVITIES_REGISTER_DATE_H
