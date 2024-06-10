#include "Math.h"

#include <math.h>

namespace Lila {

/**
 * @brief Turns degrees into radians.
*/
f64 toRadians(f64 degrees) { return degrees * RadiansMul; }

/**
 * @brief Turns radians into degrees.
*/
f64 toDegrees(f64 radians) { return radians * DegreesMul; }

/**
 * @brief Turns degrees into gradians.
*/
f64 toGradians(f64 degrees) { return degrees * GradiansMul; }

/**
 * @brief Sine function.
*/
f64 sin(f64 x) { return sinl(x); }

/**
 * @brief Cosine function.
*/
f64 cos(f64 x) { return cosl(x); }
/**
 * @brief Tangent function.
*/
f64 tan(f64 x) { return tanl(x); }

/**
 * @brief Inverse Sine function.
*/
f64 asin(f64 x) { return asinl(x); }

/**
 * @brief Inverse Cosine function.
*/
f64 acos(f64 x) { return acosl(x); }

/**
 * @brief Inverse Tangent function.
*/
f64 atan(f64 x) { return atanl(x); }

/**
 * @brief Pythagoras formula.
*/
f64 pythagoras(f64 a, f64 b) { return a * a + b * b; }

/**
 * @brief Squares Pythagoras formula.
*/
f64 sqrtPythagoras(f64 a, f64 b) { return sqrtl(a * a + b * b); }

/**
 * @brief Square root function.
*/
f64 sqrt(f64 v) { return sqrtl(v); }

/**
 * @brief Absolute function.
*/
f64 abs(f64 v) { return fabs(v); }

/**
 * @brief Flooring function.
*/
f64 floor(f64 v) { return floorl(v); }

/**
 * @brief Ceiling function.
*/
f64 ceil(f64 v) { return ceill(v); }

/**
 * @brief Rounding function.
*/
f64 round(f64 v) { return roundl(v); }

/**
 * @brief Logarithm function.
*/
f64 log(f64 v) { return logl(v); }

/**
 * @brief Logarithm base 2 function.
*/
f64 log2(f64 v) { return log2l(v); }

/**
 * @brief Exponentation function.
*/
f64 pow(f64 x, f64 y) { return powl(x,y); }

} // namespace Lila