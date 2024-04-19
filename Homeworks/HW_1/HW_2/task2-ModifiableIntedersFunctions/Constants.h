#pragma once
#include <iostream>

namespace ModifIntFuncsConstants {
	constexpr int16_t MIN = INT16_MIN;
	constexpr int16_t MAX = INT16_MAX;

	constexpr unsigned ARRAY_SIZE = MAX + (-MIN) + 1;

	constexpr int PLANE_SIZE = 10;      // Define the size of the plane for visualization
	constexpr char POINT_CHAR = '*';    // Character to represent defined points
	constexpr char EMPTY_CHAR = ' ';    // Character to represent undefined points
}