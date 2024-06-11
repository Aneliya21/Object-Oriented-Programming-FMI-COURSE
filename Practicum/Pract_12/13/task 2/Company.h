#pragma once
#include "Employee.h"
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"

class Company {

public:
	explicit Company(unsigned capacity);

	Company(const Company& other);
	Company(Company&& other) noexcept;

	Company& operator=(const Company& other);
	Company& operator=(Company&& other) noexcept;

	~Company();

	void addWorker(const Worker& toAdd);
	void addTrainee(const Trainee& toAdd);
	void addPaidTrainee(const PaidTrainee& toAdd);

	double getAverageSalary() const;

	bool TwoSum(double val) const;

	void printAll() const;

private:
	void copyFrom(const Company& other);
	void moveFrom(Company&& other);
	void free();

	void resize(unsigned newCapacity);

	unsigned getIndexToAdd(double salary) const;

	Employee** employees = nullptr;
	unsigned count = 0;
	unsigned capacity = 0;
};

