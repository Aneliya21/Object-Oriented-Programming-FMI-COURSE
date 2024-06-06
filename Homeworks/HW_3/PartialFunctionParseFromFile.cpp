#include "PartialFunctionParseFromFile.h"

PartialFunctionParseFromFile::PartialFunctionParseFromFile(const char* fileName) {
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open()) {
		throw::std::exception("file could not open");
	}

	ifs.read((char*)&N, sizeof(int16_t));
	if (N > 32) {
		throw std::exception("invalid N");
	}

	ifs.read((char*)&T, sizeof(int16_t));
	buildFunction(ifs);
	ifs.close();
}

void PartialFunctionParseFromFile::buildFunction(std::ifstream& ifs) {
	switch (T) {
	case 0: caseZero(ifs); break;
	case 1: caseOne(ifs); break;
	case 2: caseTwo(ifs); break;
	case 3: caseThree(ifs); break;
	case 4:caseFour(ifs); break;
	default:
		throw std::invalid_argument("invalid argument");
	}
}

void PartialFunctionParseFromFile::caseZero(std::ifstream& ifs) {

	Vector<int32_t> func;
	int16_t T = 0;
	readFunctionFromFile(func, ifs, N, T);

	SharedPtr<BaseCriteria> criteria(new DoubleN_PartialFunctionCriteria(func, N));

	partFuncFromFile = new PartialFunctionByCriteria(criteria);
}
void PartialFunctionParseFromFile::caseOne(std::ifstream& ifs) {

	Vector<int32_t> func;
	int16_t T = 1;
	readFunctionFromFile(func, ifs, N, T);

	SharedPtr<BaseCriteria> criteria(new NotDefinedAtPoints_PartialFunctionCriteria(func, N));

	partFuncFromFile = new PartialFunctionByCriteria(criteria);
}
void PartialFunctionParseFromFile::caseTwo(std::ifstream& ifs) {

	Vector<int32_t> func;
	int16_t T = 2;
	readFunctionFromFile(func, ifs, N, T);

	SharedPtr<BaseCriteria> criteria(new DefinedForAll_PartialFunctionCriteria(func, N));

	partFuncFromFile = new PartialFunctionByCriteria(criteria);
}
void PartialFunctionParseFromFile::caseThree(std::ifstream& ifs) {
	//int16_t T = 3;
	PartialFunctionOperation collection;
	readFunctionsCollection(collection, ifs, N);

	partFuncFromFile = new MaximumOfPartialFunctions(collection/*, N*/);
}
void PartialFunctionParseFromFile::caseFour(std::ifstream& ifs) {
	//int16_t T = 4;
	PartialFunctionOperation collection;
	readFunctionsCollection(collection, ifs, N);

	partFuncFromFile = new MinimumOfPartialFunctions(collection/*, N*/);
}

UniquePointer<PartialFunction>& PartialFunctionParseFromFile::getFunction() {
	return partFuncFromFile;
}
const UniquePointer<PartialFunction>& PartialFunctionParseFromFile::getFunction() const {
	return partFuncFromFile;
}

void readFunctionsCollection(PartialFunctionOperation& functions, std::ifstream& ifs, int16_t N) {
	if (!ifs.is_open()) {
		throw std::exception("file could not open");
	}

	for (int i = 0; i < N; i++) {
		char buffer[1024];
		char ch;
		int buffIdx = 0;

		while (ifs.get(ch)) {

			if (ch == '\0' || i == 1024 - 1) {
				buffer[buffIdx] = '\0';
				break;
			}

			buffer[buffIdx++] = ch;
		}
		PartialFunctionParseFromFile currFuncFromFile(buffer);
		functions.addFunc(currFuncFromFile.getFunction());
	}
}
void readFunctionFromFile(Vector<int32_t>& func, std::ifstream& ifs, int16_t N, int16_t T) {
	if (!ifs.is_open()) {
		throw std::exception("file could not open");
	}
	int16_t loopEnd = N;
	if (T == 0) {
		loopEnd = N * 2;
	}
	for (int i = 0; i < loopEnd; i++) {

		int currNumber;
		ifs.read((char*)&currNumber, sizeof(int));

		func.pushBack(currNumber);
		}
}
