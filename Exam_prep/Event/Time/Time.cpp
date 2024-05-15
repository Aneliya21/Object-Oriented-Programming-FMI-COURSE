#include "Time.h"

Time::Time(unsigned hours, unsigned mins, unsigned seconds) {
	setHours(hours);
	setMins(mins);
	setSeconds(seconds);
}

unsigned Time::getHours() const {
	return secondsFromMidnight / SEC_IN_HOUR;
}

unsigned Time::getMins() const {
	return (secondsFromMidnight / SEC_IN_MIN) % 60;
}

unsigned Time::getSeconds() const {
	return secondsFromMidnight % 60;
}

bool Time::setHours(unsigned hours) {
	return validateAndSet(0, 23, hours, getHours(), SEC_IN_HOUR);
}

bool Time::setMins(unsigned mins) {
	return validateAndSet(0, 59, mins, getMins(), SEC_IN_MIN);
}

bool Time::setSeconds(unsigned seconds) {
	return validateAndSet(0, 59, seconds, getSeconds(), 1);
}

void Time::tick() {
	++secondsFromMidnight %= SEC_IN_DAY;
}

void Time::serialize(std::ostream& os) const {
	os << std::setw(2) << std::setfill('0') << getHours() << ":"
	   << std::setw(2) << std::setfill('0') << getMins() << ":"
	   << std::setw(2) << std::setfill('0') << getSeconds() << std::endl;
}

bool Time::validateAndSet(unsigned lowerBoud, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned mult) {
	if (newValue >= lowerBoud && newValue <= upperBound) {
		(secondsFromMidnight -= (oldValue * mult)) += (newValue * mult);
		return true;
	}

	else {
		return false;
	}
}

int compareTimes(const Time& lhs, const Time& rhs) {
	if (lhs.getHours() < rhs.getHours()) {
		return -1;
	}
	else if (lhs.getHours() > rhs.getHours()) {
		return 1;
	}

	else {
		if (lhs.getMins() < rhs.getMins()) {
			return -1;
		}
		else if (lhs.getMins() > rhs.getMins()) {
			return 1;
		}

		else {
			if (lhs.getSeconds() < rhs.getSeconds()) {
				return -1;
			}
			else if (lhs.getSeconds() > rhs.getSeconds()) {
				return 1;
			}

			else {
				return 0;
			}
		}
	}
}
