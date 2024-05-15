#include "GamingConsole.h"

void GamingConsole::print_computer_type() const {
	std::cout << "Computer type: Gaming console" << std::endl;
}
void GamingConsole::print_perifer_devices() const {
	std::cout << "Can connect with: " << std::endl;
	std::cout << '\t' << "Joystick" << std::endl;
	std::cout << '\t' << "Monitor" << std::endl;
}