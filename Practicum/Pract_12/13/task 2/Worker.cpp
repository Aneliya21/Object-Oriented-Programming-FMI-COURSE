#include "Worker.h"

Worker::Worker() : Employee() {}

Worker::Worker(const char* name, unsigned age, double salary, unsigned months) : Employee(name, age, salary) {
    setCountOfMonthsInCompany(months);
}

Worker::Worker(const Worker& other) : Employee(other) {
    countOfMonthsInCompany = other.countOfMonthsInCompany;
}

Worker::Worker(Worker&& other) noexcept : Employee(std::move(other)) {
    countOfMonthsInCompany = other.countOfMonthsInCompany;
    other.countOfMonthsInCompany = 0;
}

Worker& Worker::operator=(const Worker& other) {
    if (this != &other) {
        Employee::operator=(other);
        countOfMonthsInCompany = other.countOfMonthsInCompany;
    }
    return *this;
}

Worker& Worker::operator=(Worker&& other) noexcept {
    if (this != &other) {
        Employee::operator=(std::move(other));
        countOfMonthsInCompany = other.countOfMonthsInCompany;
        other.countOfMonthsInCompany = 0;
    }
    return *this;
}

Employee* Worker::clone() const {
    return new Worker(*this);
}

unsigned Worker::getCountOfMonthsInCompany() const {
    return countOfMonthsInCompany;
}

void Worker::setCountOfMonthsInCompany(unsigned newCountOfMonthsInCompany) {
    countOfMonthsInCompany = newCountOfMonthsInCompany;
}

void Worker::printSalary() const {
    std::cout << getSalary() << std::endl;
}
