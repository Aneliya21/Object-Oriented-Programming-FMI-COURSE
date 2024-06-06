#include "DefinedForAll_PartialFunctionCriteria.h"

DefinedForAll_PartialFunctionCriteria::DefinedForAll_PartialFunctionCriteria(const Vector<int32_t>& newValues, int16_t N) :
																			values(newValues), N(N) {}
int32_t DefinedForAll_PartialFunctionCriteria::operator()(int32_t point) const {
	for (int16_t i = 0; i < N; i++) {
		if (values[i] == point) {
			return 1;
		}
	}
	return 0;
}