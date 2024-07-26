//
// Created by fbi168 on 18/05/24.
//

#include "../headerFiles/Register.h"

std::vector<Activity> Register::getActivitiesForDate(const std::string& date) const {
    auto activitiesElement = list.find(date);
    if (activitiesElement != list.end()) {
        return activitiesElement->second;
    } else{
        return {};
    }
}

void Register::addActivity(const Activity &activity) {
    std::string date = activity.getDate().getParsedDate();

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
    }else{
        throw std::invalid_argument("It is not possible to add an activity that overlaps with another");
    }
}

void Register::deleteActivity(const std::string &date, int pos) {
    auto activitiesElement = list.find(date);
    if(activitiesElement != list.end()){
        if(pos >= 0 && pos < list[date].size())
            list[date].erase(list[date].begin() + pos);
    }
}

void Register::deleteActivities(const std::string &date) {
    auto activitiesElement = list.find(date);
    if(activitiesElement != list.end())
        list[date].clear();
}

void Register::saveToFile() {
    std::ofstream fout;
    fout.open("../activitiesData/data.txt");

    if(fout){
        std::string line;
        for(auto& activities: list){
            for(auto& activity: activities.second){
                line = activities.first + ";" +
                       activity.getStartTime().toString() + ";" + activity.getEndTime().toString()
                       + ";" + activity.getDescription() + "\n";
                fout << line;
            }
        }
        fout.close();
    }

}

void Register::updateRegisterFormFile() {
    std::ifstream fin;
    fin.open("../activitiesData/data.txt");

    if(fin) {
        std::string line;
        while (getline(fin, line)) {
            std::vector<std::string> activitiesElement = split(line, ';');

            std::vector<std::string> buffer = split(activitiesElement[0], '-');
            Date date(std::stoi(buffer[2]), std::stoi(buffer[1]), std::stoi(buffer[0]));
            buffer = split(activitiesElement[1], ':');
            Time startTime(std::stoi(buffer[0]), std::stoi(buffer[1]));
            buffer = split(activitiesElement[2], ':');
            Time endTime(std::stoi(buffer[0]), std::stoi(buffer[1]));
            std::string description = activitiesElement[3];

            list[date.getParsedDate()].push_back(Activity(description, date, startTime, endTime));
        }
        fin.close();
    }
}

std::vector<std::string> Register::split(const std::string& line, char delimiter) {
    std::stringstream outLine(line);
    std::string segment;
    std::vector<std::string> array;
    while(std::getline(outLine, segment, delimiter))
        array.push_back(segment);
    return array;
}