#include "DoubleN_PartialFunctionCriteria.h"

DoubleN_PartialFunctionCriteria::DoubleN_PartialFunctionCriteria(const Vector<int32_t>& newElements, int16_t N) {
	this->N = N;
	arguments = Vector<int32_t>(N);
	results = Vector<int32_t>(N);
	for (int16_t i = 0; i < N; i++) {
		arguments.pushBack(newElements[i]);
		results.pushBack(newElements[i + N]);
	}
}

int32_t DoubleN_PartialFunctionCriteria::operator()(int32_t point) const {
	for (int16_t i = 0; i < N; i++) {
		if (arguments[i] == point) {
			return results[i];
		}
	}
	throw std::invalid_argument("point is not defined");
}