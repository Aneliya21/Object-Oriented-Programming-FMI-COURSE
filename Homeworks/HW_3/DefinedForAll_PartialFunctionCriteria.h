#pragma once
#include "BaseCriteria.h"

class DefinedForAll_PartialFunctionCriteria : public BaseCriteria {

public:
	DefinedForAll_PartialFunctionCriteria(const Vector<int32_t>& newValues, int16_t N);
	int32_t operator()(int32_t point) const override;

private:
	Vector<int32_t> values;
	int16_t N;
};

