#include "Graph.h"

#include "Math.h"

namespace Lila {

/**
 * @brief Linear interpolation function
 * 
 * (1 - t) * a + t * b
*/
double lerp(double a, double b, double t) {
	return (1 - t) * a + t * b;
}

/**
 * @brief Inverse Linear interpolation function
 * 
 * (t - a) / (b - a)
*/
double iLerp(double a, double b, double t) {
	return (t - a) / (b - a);
}

/**
 * @brief Linear graph function
 * 
 * a * x + b
*/
double linear(double a, double b, double x) {
	return a * x + b;
}

/**
 * @brief Parabolic graph function
 * 
 * a * x^2 + b * x + c
*/
double parabola(double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}

/**
 * @brief Quardratic formula function
 * 
 * -b ± √(b^2 - 4 * a * c) / 2 * a
*/
double quadratic(double a, double b, double c, double x, bool min) {
	if (min)
		return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

} //namespace Lila