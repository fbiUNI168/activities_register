//
// Created by fbi168 on 18/05/24.
//

#include "../headerFiles/Register.h"
#include "../exceptions/registerException.h"
#include <algorithm>

std::vector<Activity> Register::getActivitiesForDate(const std::string& date) const {
    auto activitiesElement = list.find(date);
    if (activitiesElement != list.end()) {
        return activitiesElement->second;
    } else{
        return {};
    }
}

void Register::addActivity(const Activity &activity) {
    std::string date = activity.getParsedDate();
    bool overlap = false;
    auto activitiesElement = list[date].begin();
    while(activitiesElement != list[date].end() && overlap == false){
        if(activitiesElement->isOverlapping(activity)){
            overlap = true;
        }
        activitiesElement++;
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