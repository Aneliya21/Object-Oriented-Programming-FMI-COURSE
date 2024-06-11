#pragma once
#include <iostream>

class Employee {
public:
	Employee();
	Employee(const char* name, unsigned age, double salary);

	Employee(const Employee& other);
	Employee(Employee&& other) noexcept;

	Employee& operator=(const Employee& other);
	Employee& operator=(Employee&& other) noexcept;

	virtual ~Employee();

	virtual Employee* clone() const = 0;

	const char* getName() const;
	unsigned getAge() const;
	double getSalary() const;

	void setName(const char* newName);
	void setAge(unsigned newAge);
	void setSalary(double newSalary);

	virtual void printSalary() const = 0;

private:
	void copyFrom(const Employee& other);
	void moveFrom(Employee&& other);
	void free();

	char* name = nullptr;
	unsigned age = 18;
	double salary = 0.0;
};

