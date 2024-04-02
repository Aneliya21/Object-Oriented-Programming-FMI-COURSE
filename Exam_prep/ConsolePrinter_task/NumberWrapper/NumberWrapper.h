#include "ConsolePrinter.h"

class NumberWrapper {
	int n;
	const ConsolePrinter& cp;

public:
	NumberWrapper(int n, const ConsolePrinter& cp);
	int getNumber();
	void print() const;
};