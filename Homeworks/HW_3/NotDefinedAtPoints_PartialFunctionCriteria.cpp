#include "NotDefinedAtPoints_PartialFunctionCriteria.h"

NotDefinedAtPoints_PartialFunctionCriteria::NotDefinedAtPoints_PartialFunctionCriteria(const Vector<int32_t>& newUndefinedPoints, int16_t N) : 
																						undefinedPoints(newUndefinedPoints), N(N) {}
int32_t NotDefinedAtPoints_PartialFunctionCriteria::operator()(int32_t point) const {
	for (int16_t i = 0; i < N; i++) {
		if (undefinedPoints[i] == point) {
			throw std::invalid_argument("point is not defined");
		}
	}
	return point;
}