//
// Created by fbi168 on 18/05/24.
//

#include "Register.h"
#include <algorithm>

std::vector<Activity> Register::getActivitiesForDate(const std::string& date) const {
    auto it = list.find(date);
    if (it != list.end()) {
        return it->second;
    } else{
        return {};
    }
}

void Register::addActivity(const Activity &activity) {
    std::string date = activity.getParsedDate();
    bool overlap = false;
    const auto& it = list[date].begin();
    while(it != list[date].end() && overlap == false){
        if(it->isOverlapping(activity)){
            overlap = true;
        }
    }

    if(!overlap){
        list[date].push_back(activity);
        std::sort(list[date].begin(), list[date].end(), [](const Activity& a1, const Activity& a2){
            if(a1.getStartTime().getHour() == a2.getStartTime().getHour()){
                if(a1.getStartTime().getMinute() < a2.getStartTime().getMinute())
                    return true;
                else
                    return false;
            }
            if(a1.getStartTime().getHour() < a2.getStartTime().getHour())
                return true;
            else
                return false;
        });
    }
}

void Register::deleteActivity(const std::string &date, int pos) {
    if(pos >= 0 && pos <= list[date].size()){
        auto activityList = list[date];
        activityList.erase(activityList.begin() + pos);
    }
}

void Register::deleteActivities(const std::string &date) {
    list[date].clear();
}