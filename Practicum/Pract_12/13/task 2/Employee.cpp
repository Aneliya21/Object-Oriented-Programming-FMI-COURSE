#include "Employee.h"
#pragma warning (disable : 4996)

Employee::Employee() : Employee("", 18, 0.0) {}

Employee::Employee(const char* name, unsigned age, double salary) {
	setName(name);
	setAge(age);
	setSalary(salary);
}

Employee::Employee(const Employee& other) {
	copyFrom(other);
}

Employee::Employee(Employee&& other) noexcept {
	moveFrom(std::move(other));
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		copyFrom(other);
		free();
	}
	return *this;
}

Employee& Employee::operator=(Employee&& other) noexcept {
	if (this != &other) {
		moveFrom(std::move(other));
		free();
	}
	return *this;
}

Employee::~Employee() {
	free();
}

const char* Employee::getName() const {
	return name;
}

unsigned Employee::getAge() const {
	return age;
}

double Employee::getSalary() const {
	return salary;
}

void Employee::setName(const char* newName) {
	if (!newName) {
		return;
	}
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Employee::setAge(unsigned newAge) {
	if (newAge < 18) {
		return;
	}
	age = newAge;
}

void Employee::setSalary(double newSalary) {
	if (newSalary < 0) {
		return;
	}
	salary = newSalary;
}

void Employee::copyFrom(const Employee& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;

	salary = other.salary;
}

void Employee::moveFrom(Employee&& other) {
	name = other.name;
	other.name = nullptr;

	age = other.age;
	other.age = 18;

	salary = other.salary;
	other.salary = 0.0;
}

void Employee::free() {
	delete[] name;
	name = nullptr;

	age = 18;
	salary = 0.0;
}

