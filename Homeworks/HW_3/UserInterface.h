#pragma once
#include "PartialFunctionParseFromFile.h"

class UserInterface {

public:
	UserInterface();
	void interval() const;
	void generateElements() const;

private:
	PartialFunctionParseFromFile partFuncFromFile;
	int a = 0;
	int b = 0;
};

