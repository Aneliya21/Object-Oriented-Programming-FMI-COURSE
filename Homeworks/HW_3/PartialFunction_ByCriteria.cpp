#include "PartialFunction_ByCriteria.h"
PartialFunctionByCriteria::PartialFunctionByCriteria(const SharedPtr<BaseCriteria>& criteria) 
	: criteria(criteria) {}


PartialFunction* PartialFunctionByCriteria::clone() const {
	return new PartialFunctionByCriteria(*this);
}


bool PartialFunctionByCriteria::isDefinedAtPoint(int32_t atPoint) const {
	return evaluate(atPoint).getLhs();
}


Pair<bool, int32_t> PartialFunctionByCriteria::evaluate(int32_t x) const {
	Pair<bool, int32_t> result;
	bool isDef = true;
	int32_t value = 0;

	try {
		value = criteria->operator()(x);

		result.setLhs(isDef);
		result.setRhs(value);

		return result;
	}
	catch (const std::invalid_argument& invA) {
		result.setLhs(!isDef);
		result.setRhs(value);

		return result;
	}
}