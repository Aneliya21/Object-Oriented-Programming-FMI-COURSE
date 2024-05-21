#pragma once

constexpr unsigned SECONDS_IN_HOUR = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;
class Time {

public:
	Time();
	Time(unsigned hour, unsigned min, unsigned sec);

	unsigned getHour() const;
	unsigned getMin() const;
	unsigned getSec() const;

	bool setHour(unsigned);
	bool setMin(unsigned);
	bool setSec(unsigned);

	void tick();

	bool isDinnerTime() const;
	bool isPartyTime() const;

	int compare(const Time& other) const;

	void print() const;

private:
	unsigned secondsFromMidnight = 0;

	bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned mult);
};

