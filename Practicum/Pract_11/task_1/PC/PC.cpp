#include "pc.h"

void PC::print_computer_type() const {
	std::cout << "Computer type: PC" << std::endl;
}
void PC::print_perifer_devices() const {
	std::cout << "Can connect with: " << std::endl;
	std::cout << '\t' << "Mouse" << std::endl;
	std::cout << '\t' << "Keyboard" << std::endl;
	std::cout << '\t' << "Microphone" << std::endl;
	std::cout << '\t' << "Headphones" << std::endl;
}