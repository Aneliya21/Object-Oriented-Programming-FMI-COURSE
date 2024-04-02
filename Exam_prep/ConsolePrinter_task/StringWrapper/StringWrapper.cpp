#include "StringWrapper.h"

StringWrapper::StringWrapper(const char* text, const ConsolePrinter& cp): text(text), cp(cp) {}
const char* StringWrapper::getText() const {
	return text;
}
void StringWrapper::print() const {
	cp.print(text);
}
