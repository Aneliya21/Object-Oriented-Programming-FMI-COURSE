
#pragma once
#include "Multiset.h"

int main() {
	Multiset set1(5, 4);
	set1.addNumber(2);
	set1.addNumber(2);
	set1.addNumber(4);
	set1.addNumber(5);

	set1.printSet();
	std::cout << std::endl;
}