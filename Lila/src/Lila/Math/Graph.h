#pragma once

#include "Math.h"

#include "Platform/Defines.h"

namespace Lila {

	f64 lerp(f64 a, f64 b, f64 t);
	f64 invLerp(f64 a, f64 b, f64 t);

	f64 linear(f64 a, f64 b, f64 x);
	f64 parabola(f64 a, f64 b, f64 c, f64 x);

	f64 quadratic(f64 a, f64 b, f64 c, f64 x, bool min);
}