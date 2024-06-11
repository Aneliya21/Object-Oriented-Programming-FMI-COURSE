#include "PaidTrainee.h"

PaidTrainee::PaidTrainee() : Employee() {}

PaidTrainee::PaidTrainee(const char* name, unsigned age, double salary, unsigned months, int daysLeft, double rating) : Employee(name, age, salary),
                                                                                         Worker(name, age, salary, months),
                                                                                         Trainee(name, age, salary, daysLeft) {
    setRating(rating);
}

PaidTrainee::PaidTrainee(const PaidTrainee& other) : Employee(other), Worker(other), Trainee(other) {
    rating = other.rating;
}

PaidTrainee::PaidTrainee(PaidTrainee&& other) noexcept : Employee(std::move(other)), Worker(std::move(other)), Trainee(std::move(other)) {
    rating = other.rating;
    other.rating = 0;
}

PaidTrainee& PaidTrainee::operator=(const PaidTrainee& other) {
    if (this != &other) {
        Employee::operator=(other);
        Worker::operator=(other);
        Trainee::operator=(other);
        rating = other.rating;
    }
    return *this;
}

PaidTrainee& PaidTrainee::operator=(PaidTrainee&& other) noexcept {
    if (this != &other) {
        Employee::operator=(std::move(other));
        Worker::operator=(std::move(other));
        Trainee::operator=(std::move(other));
        rating = other.rating;
        other.rating = 0;
    }
    return *this;
}

Employee* PaidTrainee::clone() const {
    return new PaidTrainee(*this);
}

double PaidTrainee::getRating() const {
    return rating;
}

void PaidTrainee::setRating(double newRating) {
    if (newRating < 0 || newRating > 100) {
        return;
    }
    rating = newRating;
}

void PaidTrainee::printSalary() const {
    std::cout << getSalary() << std::endl;
}