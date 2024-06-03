#include "Math.h"

#include <math.h>

namespace Lila {

/**
 * @brief Turns degrees into radians.
*/
double toRadians(double degrees) { return degrees * RadiansMul; }

/**
 * @brief Turns radians into degrees.
*/
double toDegrees(double radians) { return radians * DegreesMul; }

/**
 * @brief Turns degrees into gradians.
*/
double toGradians(double degrees) { return degrees * GradiansMul; }

/**
 * @brief Sine function.
*/
double sin(double x) { return sinl(x); }

/**
 * @brief Cosine function.
*/
double cos(double x) { return cosl(x); }
/**
 * @brief Tangent function.
*/
double tan(double x) { return tanl(x); }

/**
 * @brief Inverse Sine function.
*/
double asin(double x) { return asinl(x); }

/**
 * @brief Inverse Cosine function.
*/
double acos(double x) { return acosl(x); }

/**
 * @brief Inverse Tangent function.
*/
double atan(double x) { return atanl(x); }

/**
 * @brief Pythagoras formula.
*/
double pythagoras(double a, double b) { return a * a + b * b; }

/**
 * @brief Squares Pythagoras formula.
*/
double sqrtPythagoras(double a, double b) { return sqrtl(a * a + b * b); }

/**
 * @brief Square root function.
*/
double sqrt(double v) { return sqrtl(v); }

/**
 * @brief Absolute function.
*/
double abs(double v) { return fabs(v); }

/**
 * @brief Flooring function.
*/
double floor(double v) { return floorl(v); }

/**
 * @brief Ceiling function.
*/
double ceil(double v) { return ceill(v); }

/**
 * @brief Rounding function.
*/
double round(double v) { return roundl(v); }

/**
 * @brief Logarithm function.
*/
double log(double v) { return logl(v); }

/**
 * @brief Logarithm base 2 function.
*/
double log2(double v) { return log2l(v); }

/**
 * @brief Exponentation function.
*/
double pow(double x, double y) { return powl(x,y); }

} // namespace Lila