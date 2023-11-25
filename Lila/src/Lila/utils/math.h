#pragma once

#include <math.h>

#define PI 3.14159265358979323846

namespace Lila {

inline float radians(float degrees) { return degrees * (PI / 180); }
inline float degrees(float radians) { return radians * (180 / PI); }

}