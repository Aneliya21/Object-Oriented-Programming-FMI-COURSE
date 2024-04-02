#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter() : pred([](char ch) {return false; }) {}
ConsolePrinter::ConsolePrinter(bool(*pred)(char)) : pred(pred) {}

void ConsolePrinter::print(const char* str) const {
	while (*str) {
		if (!pred(*str)) {
			std::cout << *str;
		}
		else {
			std::cout << "*";
		}
		str++;
	}
	std::cout << std::endl;
}