#include "ConsolePrinter.h"
#include "NumberWrapper.h"
#include "StringWrapper.h"
#include "Functions.h"

int main() {
	{
		ConsolePrinter cp1(Funcs::isLowerCase);

		StringWrapper sW1("TExtTOtestStrINg", cp1);

		sW1.print();
	}
	{
		ConsolePrinter cp2(Funcs::isDigit);

		NumberWrapper nW2(23242, cp2);

		nW2.print();
	}
	{
		ConsolePrinter cp3(Funcs::isUpperCase);

		StringWrapper sW3("TExtTOtestStrINg", cp3);

		sW3.print();
	}
}