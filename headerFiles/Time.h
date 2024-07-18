//
// Created by fbi168 on 22/05/24.
//

#ifndef ACTIVITIES_REGISTER_TIME_H
#define ACTIVITIES_REGISTER_TIME_H
#include <iomanip>
#include <sstream>

class Time {
public:
    Time(int hour, int minute);
    Time(): Time(0, 0){}

    int getHour() const;

    int getMinute() const;

    void setHour(int hour);

    void setMinute(int minutes);

    bool operator==(const Time &time) const;

    std::string toString() const;

private:
    bool validTime(int hour, int minute) const;

    int hour;
    int minute;
};


#endif //ACTIVITIES_REGISTER_TIME_H