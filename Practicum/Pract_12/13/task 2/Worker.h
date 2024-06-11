#pragma once
#include "Employee.h"

class Worker : virtual public Employee {

public:
	Worker();
	Worker(const char* name, unsigned age, double salary, unsigned months);

	Worker(const Worker& other);
	Worker(Worker&& other) noexcept;

	Worker& operator=(const Worker& other);
	Worker& operator=(Worker&& other) noexcept;

	Employee* clone() const override;

	unsigned getCountOfMonthsInCompany() const;
	void setCountOfMonthsInCompany(unsigned newCountOfMonthsInCompany);

	void printSalary() const override;

private:
	unsigned countOfMonthsInCompany = 0;
};

