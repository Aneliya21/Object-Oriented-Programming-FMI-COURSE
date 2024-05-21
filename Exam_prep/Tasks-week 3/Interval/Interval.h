#pragma once

class Interval {

public:
	Interval();
	Interval(int a, int b);

	void setA(int a);
	void setB(int b);

	int getA() const;
	int getB() const;

	unsigned getIntervalLength() const;
	bool isInInterval(int n) const;

	unsigned getPrimesCount() const;
	unsigned getPalindomesCount() const;

	bool isSubInterval(const Interval& other) const;

private:
	int a = 0;
	int b = 0;

	unsigned getCountBasedOnCondition(bool(*pred)(int)) const;
};

Interval intersectIntervals(const Interval& lhs, const Interval& rhs);
