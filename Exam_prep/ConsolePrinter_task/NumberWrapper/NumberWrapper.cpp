#include "NumberWrapper.h"

NumberWrapper::NumberWrapper(int n, const ConsolePrinter& cp):n(n), cp(cp) {}

int NumberWrapper::getNumber() {
	return n;
}
void NumberWrapper::print() const {
	cp.print(std::to_string(n).c_str());
}