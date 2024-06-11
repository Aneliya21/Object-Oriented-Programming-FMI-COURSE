#include "Trainee.h"

Trainee::Trainee() : Employee() {}

Trainee::Trainee(const char* name, unsigned age, double salary, int daysLeft) : Employee(name, age, salary) { 
    setDaysLeft(daysLeft);
}

Trainee::Trainee(const Trainee& other) : Employee(other) {
    daysLeft = other.daysLeft;
}

Trainee::Trainee(Trainee&& other) noexcept : Employee(std::move(other)) {
    daysLeft = other.daysLeft;
    other.daysLeft = 0;
}

Trainee& Trainee::operator=(const Trainee& other) {
    if (this != &other) {
        Employee::operator=(other);
        daysLeft = other.daysLeft;
    }
    return *this;
}

Trainee& Trainee::operator=(Trainee&& other) noexcept {
    if (this != &other) {
        Employee::operator=(std::move(other));
        daysLeft = other.daysLeft;
        other.daysLeft = 0;
    }
    return *this;
}

Employee* Trainee::clone() const {
    return new Trainee(*this);
}

int Trainee::getDaysLeft() const {
    return daysLeft;
}

void Trainee::setDaysLeft(int days) {
    daysLeft = days;
}

void Trainee::printSalary() const {
    std::cout << getSalary() << std::endl;
}
