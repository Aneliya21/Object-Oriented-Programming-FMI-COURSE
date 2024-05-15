#include "Laptop.h"

void Laptop::print_computer_type() const {
	std::cout << "Computer type: Laptop" << std::endl;
}
void Laptop::print_perifer_devices() const {
	std::cout << "Can connect with: " << std::endl;
	std::cout << '\t' << "Mouse" << std::endl;
	std::cout << '\t' << "Pad" << std::endl;
	std::cout << '\t' << "Keyboard" << std::endl;
	std::cout << '\t' << "Monitor" << std::endl;
}