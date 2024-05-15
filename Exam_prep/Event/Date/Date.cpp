#include "Date.h"

Date::Date(unsigned day, unsigned month, unsigned year) {
	setYear(year);
	setMonth(month);
	setDay(day);
}

unsigned Date::getDay() const {
	if (!good()) {
		return 0;
	}
	return day;
}

unsigned Date::getMonth() const {
	if (!good()) {
		return 0;
	}
	return month;
}

unsigned Date::getYear() const {
	if (!good()) {
		return 0;
	}
	return year;
}

void Date::setDay(unsigned day) {
	if (!good()) {
		return;
	}

	this->day = day;

	isModif = true;
	validateDate();
}

void Date::setMonth(unsigned month) {
	if (!good()) {
		return;
	}

	this->month = month;

	isModif = true;
	validateDate();
}

void Date::setYear(unsigned year) {
	if (!good()) {
		return;
	}

	this->year = year;

	if (isLeapYear()) {
		MAX_DAYS[1] = 29;
	}

	else {
		MAX_DAYS[1] = 28;
	}

	isModif = true;
	validateDate();
}

void Date::print() const {
	if (!good()) {
		return;
	}

	std::cout << day << "." << month << "." << year << std::endl;
}

void Date::goToNextDay() {
	if (!good()) {
		return;
	}

	if (year == 1916 && month == 3 && day == 31) {
		day = 14;
		month = 4;
	}

	else {
		day++;
		if (day > MAX_DAYS[month - 1]) {
			day = 1;
			setMonth((month == 12) ? 1 : (month + 1));

			if (month == 1) {
				setYear(year + 1);
			}
		}
	}
	isModif = true;
}

int Date::getDayOfWeek() const {
	if (!good()) {
		return -1;
	}

	if (!isModif) {
		return dayOfWeek;
	}

	Date date(1, 1, 1);
	int day = 5;

	while (compareDates(date, *this) != 0) {
		date.goToNextDay();
		day++;
		day %= 7;
	}

	dayOfWeek = day + 1;
	isModif = false;

	return dayOfWeek;
}

bool Date::good() const {
	return isDateInValidState;
}

void Date::clear() {
	isDateInValidState = true;
	day = month = year = 1;
}

bool Date::isLeapYear() const {
	if (year <= 1916) {
		return year % 4 == 0;
	}

	else {
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}
}
void Date::validateDate() {
	isDateInValidState = !((month == 0 || month > 12) ||
							(day == 0 || day > MAX_DAYS[month - 1]) ||
								(year == 0) || (year == 1916 && month == 4 && day < 14));
}

int compareDates(const Date& lhs, const Date& rhs) {
	if (lhs.getYear() < rhs.getYear()) {
		return -1;
	}
	else if (lhs.getYear() > rhs.getYear()) {
		return 1;
	}

	else {
		if (lhs.getMonth() < rhs.getMonth()) {
			return -1;
		}
		else if (lhs.getMonth() > rhs.getMonth()) {
			return 1;
		}

		else {
			if (lhs.getDay() < rhs.getDay()) {
				return -1;
			}
			else if (lhs.getDay() > rhs.getDay()) {
				return 1;
			}

			else {
				return 0;
			}
		}
	}
}