#include "MaximumOfPartialFunctions.h"

MaximumOfPartialFunctions::MaximumOfPartialFunctions(PartialFunctionOperation& functions) : functions(std::move(functions)) {}

PartialFunction* MaximumOfPartialFunctions::clone() const {
	return new MaximumOfPartialFunctions(*this);
}
bool MaximumOfPartialFunctions::isDefinedAtPoint(int32_t atPoint) const {
	for (size_t i = 0; i < functions.getCount(); i++) {
		if (!functions[i]->isDefinedAtPoint(atPoint)) {
			return false;
		}
	}
	return true;
}
Pair<bool, int32_t> MaximumOfPartialFunctions::evaluate(int32_t x) const {
	Pair<bool, int32_t> result;

	bool isDefined = functions[0]->evaluate(x).getLhs();
	int32_t maxResult = functions[0]->evaluate(x).getRhs();

	for (size_t i = 1; i < functions.getCount(); i++) {
		int32_t currentResult = functions[i]->evaluate(x).getRhs();
		isDefined = functions[i]->evaluate(x).getLhs();
		if (maxResult < currentResult) {
			maxResult = currentResult;
		}
		if (!isDefined) {
			result.setLhs(isDefined);
			result.setRhs(maxResult);
			return result;
		}
	}
	result.setLhs(isDefined);
	result.setRhs(maxResult);
	return result;
}