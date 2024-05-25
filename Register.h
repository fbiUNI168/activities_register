//
// Created by fbi168 on 18/05/24.
//

#ifndef ACTIVITIES_REGISTER_REGISTER_H
#define ACTIVITIES_REGISTER_REGISTER_H
#include "Activity.h"
#include "Date.h"
#include <map>
#include <vector>

class Register {
public:

    std::vector<Activity> getActivitiesForDate(const std::string& date) const;

    void addActivity(const Activity& activity);

    void deleteActivity(const std::string& date, int pos);

    void deleteActivities(const std::string& date);


private:
    std::map<std::string ,std::vector<Activity>> list;
};


#endif //ACTIVITIES_REGISTER_REGISTER_H
