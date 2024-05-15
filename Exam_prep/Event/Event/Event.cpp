#include <iostream>
#include "Event.h"

Event::Event() : Event("", 1,1,1,0,0,0,0,0,0) {}

Event::Event(const char* name, unsigned day, unsigned month, unsigned year, 
            unsigned startHours, unsigned startMins, unsigned startSeconds, 
            unsigned endHours, unsigned endMins, unsigned endSeconds) : 
                    date(day, month, year), startTime(startHours, startMins, startSeconds), 
                                            endTime(endHours, endMins, endSeconds) {
    setName(name);
    validateTimes();
}

Event::Event(const char* name, const Date& date, const Time& startTime, const Time& endTime) : 
                    date(date), startTime(startTime), endTime(endTime) {
    setName(name);
}

const char* Event::getName() const {
    return name;
}

const Date& Event::getDate() const {
    return date;
}

const Time& Event::getStartTime() const {
    return startTime;
}

const Time& Event::getEndTime() const {
    return endTime;
}

void Event::setName(const char* name) {
    if (!name || strlen(name) > MAX_LEN) {
        return;
    }
    else {
        strcpy(this->name, name);
    }
}
void Event::validateTimes() {
    if (compareTimes(startTime, endTime) > 0) {
        std::swap(startTime, endTime);
    }
}


int main() {

}
