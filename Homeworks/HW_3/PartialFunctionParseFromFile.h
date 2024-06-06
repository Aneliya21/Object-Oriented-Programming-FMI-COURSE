#pragma once
#include <fstream>
#include "DoubleN_PartialFunctionCriteria.h"
#include "NotDefinedAtPoints_PartialFunctionCriteria.h"
#include "DefinedForAll_PartialFunctionCriteria.h"
#include "MaximumOfPartialFunctions.h"
#include "MinimumOfPartialFunctions.h"

#include "PartialFunction_ByCriteria.h"
#include "Unique_ptr.hpp"

class PartialFunctionParseFromFile {

public:

	PartialFunctionParseFromFile(const char* fileName);
	UniquePointer<PartialFunction>& getFunction();
	const UniquePointer<PartialFunction>& getFunction() const;

private:
	UniquePointer<PartialFunction> partFuncFromFile;
	int16_t N = 0;
	int16_t T = 0;

	void buildFunction(std::ifstream& ifs);

	void caseZero(std::ifstream& ifs);
	void caseOne(std::ifstream& ifs);
	void caseTwo(std::ifstream& ifs);
	void caseThree(std::ifstream& ifs);
	void caseFour(std::ifstream& ifs);
};

void readFunctionsCollection(PartialFunctionOperation& functions, std::ifstream& ifs, int16_t N);
void readFunctionFromFile(Vector<int32_t>& func, std::ifstream& ifs, int16_t N, int16_t T);

