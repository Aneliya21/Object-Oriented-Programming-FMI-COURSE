#include "ConsolePrinter.h"

class StringWrapper {
	const char* text;
	const ConsolePrinter& cp;

public:
	StringWrapper(const char* text, const ConsolePrinter& cp);
	const char* getText() const;
	void print() const;
};