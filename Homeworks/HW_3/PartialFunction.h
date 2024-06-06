#pragma once
#include <iostream>
#include "Pair.hpp"

class PartialFunction {

public:
	virtual PartialFunction* clone() const = 0;
	virtual bool isDefinedAtPoint(int32_t atPoint) const = 0;
	virtual Pair<bool, int32_t> evaluate(int32_t x) const = 0;
	virtual ~PartialFunction() = default;
};

