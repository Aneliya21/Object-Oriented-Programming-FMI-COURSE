#pragma once

#include <iostream>

class Computer {

public:
	Computer() = default;

	Computer(const Computer& other);
	Computer(Computer&& other) noexcept;

	Computer& operator=(const Computer& other);
	Computer& operator=(Computer&& other) noexcept;

	void set_processor_power(double new_processor_power);
	void set_videoCard_model(const char* new_videoCard_model);
	void set_power_supply(int new_power_supply);
	void set_RAM_quantity(int new_RAM_quantity);

	virtual void print_computer_type() const = 0;
	virtual void print_perifer_devices() const = 0;

	virtual ~Computer();

private:
	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other);
	void free();

	double processor_power = 0.0;
	char* videoCard_model = nullptr;
	int power_supply = 0;
	int RAM_quantity = 0;

};

