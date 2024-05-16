#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>

constexpr unsigned SEC_IN_HOUR = 3600;
constexpr unsigned SEC_IN_MIN = 60;
constexpr unsigned SEC_IN_DAY = 24 * 3600;

class Time {

public:
	Time() = default;
	Time(unsigned hours, unsigned mins, unsigned seconds);

	unsigned getHours() const;
	unsigned getMins() const;
	unsigned getSeconds() const;

	bool setHours(unsigned hours);
	bool setMins(unsigned mins);
	bool setSeconds(unsigned seconds);

	void tick();
	void serialize(std::ostream& os) const;

private:
	bool validateAndSet(unsigned lowerBoud, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned mult);

	unsigned secondsFromMidnight = 0;
};

int compareTimes(const Time& lhs, const Time& rhs);
