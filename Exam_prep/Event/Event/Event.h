#pragma once

#include "Time.h"
#include "Date.h"

constexpr unsigned MAX_LEN = 20;

class Event {

public:
	Event();
	Event(const char* name, unsigned day, unsigned month, unsigned year,
		unsigned startHours, unsigned startMins, unsigned startSeconds,
		unsigned endHours, unsigned endMins, unsigned endSeconds);
	Event(const char* name, const Date& date, const Time& startTime, const Time& endTime);

	const char* getName() const;
	const Date& getDate() const;
	const Time& getStartTime() const;
	const Time& getEndTime() const;

private:
	void setName(const char* name);
	void validateTimes();

	char name[MAX_LEN] = "";
	Date date;
	Time startTime;
	Time endTime;
};

