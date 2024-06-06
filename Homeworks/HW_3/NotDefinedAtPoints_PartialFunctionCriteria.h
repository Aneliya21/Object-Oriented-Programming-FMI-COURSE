#pragma once
#include "BaseCriteria.h"

class NotDefinedAtPoints_PartialFunctionCriteria : public BaseCriteria {

public:
	NotDefinedAtPoints_PartialFunctionCriteria(const Vector<int32_t>& newUndefinedPoints, int16_t N);
	int32_t operator()(int32_t point) const override;

private:
	Vector<int32_t> undefinedPoints;
	int16_t N;
};

