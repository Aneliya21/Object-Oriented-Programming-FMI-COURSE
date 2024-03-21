#pragma once
#include "Constants.h"
#include "Additional_Functions.h"
#include <iomanip>
#include <iostream>

class Time {

private:
    unsigned secondsFromMidnight;

    bool validateAndSet(unsigned lowerBound, unsigned upperBound,
        unsigned newValue, unsigned oldVlaue, unsigned multiplier);

public:

    Time();
    Time(unsigned hours, unsigned mins, unsigned seconds);

    unsigned getHours() const;
    unsigned getMins() const;
    unsigned getSeconds() const;

    unsigned getSecondsFromMidnight() const;

    bool setHours(unsigned hours);
    bool setMins(unsigned mins);
    bool setSeconds(unsigned seconds);

    void serialize(std::ostream& os) const;

    void printTime() const;
};

