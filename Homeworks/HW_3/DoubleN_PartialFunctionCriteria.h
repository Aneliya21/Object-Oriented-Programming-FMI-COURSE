#pragma once
#include "BaseCriteria.h"

class DoubleN_PartialFunctionCriteria : public BaseCriteria {

public:
	DoubleN_PartialFunctionCriteria(const Vector<int32_t>& elements, int16_t N);
	int32_t operator()(int32_t point) const override;

private:
	Vector<int32_t> arguments;
	Vector<int32_t> results;
	int16_t N;
};

