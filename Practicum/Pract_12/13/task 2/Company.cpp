#include "Company.h"

Company::Company(unsigned capacity) {
    count = 0;
    this->capacity = capacity;

    employees = new Employee * [capacity];
    for (unsigned i = 0; i < capacity; i++) {
        employees[i] = nullptr;
    }
} 

Company::Company(const Company& other) {
    copyFrom(other);
}

Company::Company(Company&& other) noexcept {
    moveFrom(std::move(other));
}

Company& Company::operator=(const Company& other) {
    if (this != &other) {
        copyFrom(other);
        free();
    }
    return *this;
}

Company& Company::operator=(Company&& other) noexcept {
    if (this != &other) {
        moveFrom(std::move(other));
        free();
    }
    return *this;
}

Company::~Company() {
    free();
}

void Company::addWorker(const Worker& toAdd) {
    if (count == capacity) {
        resize(capacity * 2);
    }

    unsigned index = getIndexToAdd(toAdd.getSalary());
    for (unsigned i = count; i > index; i--) {
        employees[i] = employees[i - 1];
    }
    employees[index] = toAdd.clone();
    count++;
}

void Company::addTrainee(const Trainee& toAdd) {
    if (count == capacity) {
        resize(capacity * 2);
    }

    unsigned index = getIndexToAdd(toAdd.getSalary());
    for (unsigned i = count; i > index; i--) {
        employees[i] = employees[i - 1];
    }
    employees[index] = toAdd.clone();
    count++;
}

void Company::addPaidTrainee(const PaidTrainee& toAdd) {
    if (count == capacity) {
        resize(capacity * 2);
    }

    unsigned index = getIndexToAdd(toAdd.getSalary());
    for (unsigned i = count; i > index; i--) {
        employees[i] = employees[i - 1];
    }
    employees[index] = toAdd.clone();
    count++;
}

double Company::getAverageSalary() const {
    double sumOfAll = 0.0;
    for (unsigned i = 0; i < count; i++) {
        sumOfAll += employees[i]->getSalary();
    }

    return sumOfAll / count;
}

bool Company::TwoSum(double val) const {
    return false;
}

void Company::copyFrom(const Company& other) {

    employees = new Employee * [other.capacity];

    capacity = other.capacity;
    count = other.count;

    for (unsigned i = 0; i < count; i++) {
        employees[i] = other.employees[i]->clone();
    }
}

void Company::moveFrom(Company&& other) {
    employees = other.employees;
    other.employees = nullptr;

    count = other.count;
    capacity = other.capacity;

    other.count = other.capacity = 0;
}

void Company::free() {
    for (unsigned i = 0; i < count; i++) {
        delete employees[i];
    }
    delete[] employees;

    count = capacity = 0;
}

void Company::resize(unsigned newCapacity) {
    Employee** temp = new Employee * [newCapacity];

    for (unsigned i = 0; i < count; i++) {
        temp[i] = employees[i];
    }

    capacity = newCapacity;

    delete[] employees;
    employees = temp;
}

unsigned Company::getIndexToAdd(double salary) const {
    for (unsigned i = 0; i < count; i++) {
        if (!employees[i]) {
            return 0;
        }
        if (salary <= employees[i]->getSalary()) {
            return i;
        }
    }
    return count;
}

void Company::printAll() const {
    for (unsigned i = 0; i < count; i++) {
        employees[i]->printSalary();
    }
}