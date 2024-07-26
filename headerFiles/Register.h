//
// Created by fbi168 on 18/05/24.
//

#ifndef ACTIVITIES_REGISTER_REGISTER_H
#define ACTIVITIES_REGISTER_REGISTER_H
#include "Activity.h"
#include "Date.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <filesystem>

class Register {
public:
    Register() = default;

    std::vector<Activity> getActivitiesForDate(const std::string& date) const;

    void addActivity(const Activity& activity);

    void deleteActivity(const std::string& date, int pos);

    void deleteActivities(const std::string& date);

    void saveToFile();

    void updateRegisterFormFile();

private:
    std::map<std::string ,std::vector<Activity>> list;

    std::vector<std::string> split(const std::string& line, char delimiter);
};


#endif //ACTIVITIES_REGISTER_REGISTER_H
