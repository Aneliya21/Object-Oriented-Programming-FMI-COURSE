#pragma once
#include "Employee.h"

class Trainee : virtual public Employee {
	
public:
	Trainee();
	Trainee(const char* name, unsigned age, double salary, int daysLeft);

	Trainee(const Trainee& other);
	Trainee(Trainee&& other) noexcept;

	Trainee& operator=(const Trainee& other);
	Trainee& operator=(Trainee&& other) noexcept;

	Employee* clone() const override;

	int getDaysLeft() const;
	void setDaysLeft(int days);

	void printSalary() const override;

private:
	int daysLeft = 0;
};

