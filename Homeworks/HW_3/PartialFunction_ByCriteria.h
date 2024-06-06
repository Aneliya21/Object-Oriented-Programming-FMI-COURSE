#pragma once
#include "PartialFunction.h"
#include "Shared_ptr.hpp"

#include "BaseCriteria.h"

class PartialFunctionByCriteria : public PartialFunction {

public:
	PartialFunctionByCriteria(const SharedPtr<BaseCriteria>& criteria);

	PartialFunction* clone() const override;

	bool isDefinedAtPoint(int32_t atPoint) const override;
	Pair<bool, int32_t> evaluate(int32_t x) const override;

private:
	SharedPtr<BaseCriteria> criteria;
};

