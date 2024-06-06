#include "MinimumOfPartialFunctions.h"

MinimumOfPartialFunctions::MinimumOfPartialFunctions(PartialFunctionOperation& functions) : functions(std::move(functions)) {}

PartialFunction* MinimumOfPartialFunctions::clone() const {
	return new MinimumOfPartialFunctions(*this);
}
bool MinimumOfPartialFunctions::isDefinedAtPoint(int32_t atPoint) const {
	for (size_t i = 0; i < functions.getCount(); i++) {
		if (!functions[i]->isDefinedAtPoint(atPoint)) {
			return false;
		}
	}
	return true;
}
Pair<bool, int32_t> MinimumOfPartialFunctions::evaluate(int32_t x) const {
	Pair<bool, int32_t> result;

	bool isDefined = functions[0]->evaluate(x).getLhs();
	int32_t minResult = functions[0]->evaluate(x).getRhs();

	for (size_t i = 1; i < functions.getCount(); i++) {
		int32_t currentResult = functions[i]->evaluate(x).getRhs();
		isDefined = functions[i]->evaluate(x).getLhs();
		if (minResult > currentResult) {
			minResult = currentResult;
		}
		if (!isDefined) {
			result.setLhs(isDefined);
			result.setRhs(minResult);
			return result;
		}
	}
	result.setLhs(isDefined);
	result.setRhs(minResult);
	return result;
}