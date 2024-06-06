#include "UserInterface.h"

static const char FILE_NAME[] = "func.dat";
static const char CHOOSE_MODE[] = "Choose mode for work(1 or 2): ";
static const char WRONG_INPUT[] = "Wrong input";
static const char INPUT_A[] = "Input a:";
static const char INPUT_B[] = "Input b:";
static const char TYPE_NEXT[] = "Type 'next' to see the next element:";
static const char NEXT[] = "next";
static const char NO_MORE_ELEMENTS[] = "No more elements";


UserInterface::UserInterface() : partFuncFromFile(FILE_NAME) {
	int input;
	std::cout << CHOOSE_MODE;
	std::cin >> input;
	if (input == 1) {
		std::cout << INPUT_A;
		std::cin >> a;
		std::cout << INPUT_B;
		std::cin >> b;
		try {
			interval();
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	else if (input == 2) {
		generateElements();
	}
	else {
		std::cout << WRONG_INPUT << std::endl;
	}
}

void UserInterface::interval() const {
	if (a > b) {
		throw std::exception("interval is not valid");
	}
	for (int i = a; i < b; i++) {
		bool current = partFuncFromFile.getFunction()->isDefinedAtPoint(i);
		if (current) {
			int32_t result = partFuncFromFile.getFunction()->evaluate(i).getRhs();
			std::cout << "f(" << i << ") = " << result;
			std::cout << " ";
		}
	}
}
void UserInterface::generateElements() const {
	int i = INT32_MIN;
	std::cout << TYPE_NEXT << std::endl;
	while (true) {
		char buffer[10];
		std::cin >> buffer;
		if (strcmp(buffer, NEXT) == 0) {
			while (!partFuncFromFile.getFunction()->isDefinedAtPoint(i) && i != INT32_MAX) {
				i++;
			}
			if (i == INT_MAX) {
				std::cout << NO_MORE_ELEMENTS;
				break;
			}
			int32_t result = partFuncFromFile.getFunction()->evaluate(i).getRhs();
			std::cout << "f(" << i << ") = " << result;
			std::cout << std::endl;

			i++;
		}
	}
}