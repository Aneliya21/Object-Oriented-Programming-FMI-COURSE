#include <iostream>
#include <iomanip>
#include "Time.h"

Time::Time(): Time(0,0,0) {}
Time::Time(unsigned hour, unsigned min, unsigned sec) {
    setHour(hour);
    setMin(min);
    setSec(sec);
}

unsigned Time::getHour() const {
    return secondsFromMidnight / SECONDS_IN_HOUR;
}
unsigned Time::getMin() const {
    return (secondsFromMidnight / 60) % 60;
}
unsigned Time::getSec() const {
    return secondsFromMidnight % 60;
}

bool Time::setHour(unsigned hour) {
    return validateAndSet(0, 23, hour, getHour(), SECONDS_IN_HOUR);
}
bool Time::setMin(unsigned min) {
    return validateAndSet(0, 59, min, getMin(), SECONDS_IN_MINUTE);
}
bool Time::setSec(unsigned sec) {
    return validateAndSet(0, 59, sec, getSec(), 1);
}

void Time::tick() {
    secondsFromMidnight++;
    secondsFromMidnight %= DAY_SECONDS;
}

bool Time::isDinnerTime() const {
    unsigned hour = getHour();
    unsigned min = getMin();
    unsigned sec = getSec();

    return (((hour == 20 && min >= 30) || (hour >= 21)) && (hour <= 22 && min == 0 && sec == 0));
}
bool Time::isPartyTime() const {
    unsigned hour = getHour();
    unsigned min = getMin();
    unsigned sec = getSec();

    return (hour >= 23 && (hour <= 6 && min==0 && sec==0));
}

int Time::compare(const Time& other) const {
    if (secondsFromMidnight > other.secondsFromMidnight) {
        return 1;
    }
    else if (secondsFromMidnight < other.secondsFromMidnight) {
        return -1;
    }
    else {
        return 0;
    }
}

void Time::print() const {
    std::cout << std::setw(2) << std::setfill('0') << getHour() << ":"
              << std::setw(2) << std::setfill('0') << getMin() << ":"
              << std::setw(2) << std::setfill('0') << getSec() << std::endl;
}

bool Time::validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned mult) {
    if (newValue >= lowerBound && newValue <= upperBound) {
        (secondsFromMidnight -= (oldValue * mult)) += (newValue * mult);
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    
}
