#include "Computer.h"

#pragma warning (disable : 4996)

Computer::Computer(const Computer& other) {
	copyFrom(other);
}
Computer::Computer(Computer&& other) noexcept {
	moveFrom(std::move(other));
}

Computer& Computer::operator=(const Computer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Computer& Computer::operator=(Computer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Computer::set_processor_power(double new_processor_power) {
	processor_power = new_processor_power;
}
void Computer::set_videoCard_model(const char* new_videoCard_model) {
	if (!new_videoCard_model) {
		return;
	}
	videoCard_model = new char[strlen(new_videoCard_model) + 1];
	strcpy(videoCard_model, new_videoCard_model);
}
void Computer::set_power_supply(int new_power_supply) {
	power_supply = new_power_supply;
}
void Computer::set_RAM_quantity(int new_RAM_quantity) {
	new_RAM_quantity = RAM_quantity;
}

Computer::~Computer() {
	free();
}

void Computer::copyFrom(const Computer& other) {
	processor_power = other.processor_power;

	videoCard_model = new char[strlen(other.videoCard_model) + 1];
	strcpy(videoCard_model, other.videoCard_model);

	power_supply = other.power_supply;

	RAM_quantity = other.RAM_quantity;
}
void Computer::moveFrom(Computer&& other) {
	processor_power = other.processor_power;
	other.processor_power = 0.0;

	videoCard_model = other.videoCard_model;
	other.videoCard_model = nullptr;

	power_supply = other.power_supply;
	other.power_supply = 0;

	RAM_quantity = other.RAM_quantity;
	other.RAM_quantity = 0;
}
void Computer::free() {
	delete[] videoCard_model;

	processor_power = 0.0;
	power_supply = RAM_quantity = 0;
}