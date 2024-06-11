#pragma once
#include "Worker.h"
#include "Trainee.h"

class PaidTrainee : public Worker, public Trainee {

public:
	PaidTrainee();
	PaidTrainee(const char* name, unsigned age, double salary, unsigned months, int daysLeft, double rating);

	PaidTrainee(const PaidTrainee& other);
	PaidTrainee(PaidTrainee&& other) noexcept;

	PaidTrainee& operator=(const PaidTrainee& other);
	PaidTrainee& operator=(PaidTrainee&& other) noexcept;

	Employee* clone() const override;

	double getRating() const;
	void setRating(double newRating);

	void printSalary() const override;

private:
	double rating = 0;
};

