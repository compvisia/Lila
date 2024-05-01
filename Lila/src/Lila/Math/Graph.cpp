#include "Graph.h"

#include "Math.h"

namespace Lila {

	double lerp(double a, double b, double t) {
		return (1 - t) * a + t * b;
	}
	double invLerp(double a, double b, double t) {
		return (t - a) / (b - a);
	}

	double linear(double a, double b, double x) {
		return a * x + b;
	}
	double parabola(double a, double b, double c, double x) {
		return a * x * x + b * x + c;
	}

	double quadratic(double a, double b, double c, double x, bool min) {
		if (min)
			return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}
}