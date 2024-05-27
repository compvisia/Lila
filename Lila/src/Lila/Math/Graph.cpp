#include "Graph.h"

#include "Math.h"

namespace Lila {

	f64 lerp(f64 a, f64 b, f64 t) {
		return (1 - t) * a + t * b;
	}
	f64 invLerp(f64 a, f64 b, f64 t) {
		return (t - a) / (b - a);
	}

	f64 linear(f64 a, f64 b, f64 x) {
		return a * x + b;
	}
	f64 parabola(f64 a, f64 b, f64 c, f64 x) {
		return a * x * x + b * x + c;
	}

	f64 quadratic(f64 a, f64 b, f64 c, f64 x, b8 min) {
		if (min)
			return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}
}