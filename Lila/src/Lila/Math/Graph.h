#pragma once

#include "Math.h"

namespace Lila {

	double lerp(double a, double b, double t);
	double invLerp(double a, double b, double t);

	double linear(double a, double b, double x);
	double parabola(double a, double b, double c, double x);

	double quadratic(double a, double b, double c, double x, bool min);
}