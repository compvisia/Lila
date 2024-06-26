#include "Graph.h"

#include "Math.h"

namespace Lila {

	/**
	 * @brief Linear interpolation function.
	 * 
	 * (1 - t) * a + t * b
	*/
	f64 lerp(f64 a, f64 b, f64 t) {
	return (1 - t) * a + t * b;
	}

	/**
	 * @brief Inverse Linear interpolation function.
	 * 
	 * (t - a) / (b - a)
	*/
	f64 iLerp(f64 a, f64 b, f64 t) {
	return (t - a) / (b - a);
	}

	/**
	 * @brief Linear graph function.
	 * 
	 * a * x + b
	*/
	f64 linear(f64 a, f64 b, f64 x) {
	return a * x + b;
	}

	/**
	 * @brief Parabolic graph function.
	 * 
	 * a * x^2 + b * x + c
	*/
	f64 parabola(f64 a, f64 b, f64 c, f64 x) {
	return a * x * x + b * x + c;
	}

	/**
	 * @brief Quardratic formula function.
	 * 
	 * -b ± √(b^2 - 4 * a * c) / 2 * a
	*/
	f64 quadratic(f64 a, f64 b, f64 c, f64 x, bool min) {
	if (min)
	return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}

} //namespace Lila