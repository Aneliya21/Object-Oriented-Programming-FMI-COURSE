#pragma once
#include <iostream>
#include "Pair.hpp"
#include "Vector.hpp"

class BaseCriteria {

public:
	virtual int32_t operator()(int32_t) const = 0;
	virtual ~BaseCriteria() = default;
};

