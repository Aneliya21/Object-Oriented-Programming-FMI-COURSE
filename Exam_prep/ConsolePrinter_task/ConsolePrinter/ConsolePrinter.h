#include <iostream>
#include <string>
#pragma warning (disable:4996)

class ConsolePrinter {
	bool (*pred)(char);

public:
	ConsolePrinter();
	ConsolePrinter(bool(*pred)(char));
	void print(const char* str) const;
};