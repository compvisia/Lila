#include "Math.h"

#include <math.h>

namespace Lila {

	f64 toRadians(f64 degrees) { return degrees * RadiansMul; }
	f64 toDegrees(f64 radians) { return radians * DegreesMul; }
	f64 toGradians(f64 degrees) { return degrees * GradiansMul; }


	f64 sin(f64 x) { return sinl(x); }
	f64 cos(f64 x) { return cosl(x); }
	f64 tan(f64 x) { return tanl(x); }

	f64 asin(f64 x) { return asinl(x); }
	f64 acos(f64 x) { return acosl(x); }
	f64 atan(f64 x) { return atanl(x); }

	f64 pythagoras(f64 a, f64 b) { return a * a + b * b; }
	f64 sqrtPythagoras(f64 a, f64 b) { return sqrtl(a * a + b * b); }

	f64 sqrt(f64 v) { return sqrtl(v); }

	f64 abs(f64 v) { return fabs(v); }

	f64 floor(f64 v) { return floorl(v); }
	f64 ceil(f64 v) { return ceill(v); }
	f64 round(f64 v) { return roundl(v); }
	
	f64 log(f64 v) { return logl(v); }
	f64 log2(f64 v) { return log2l(v); }
	
	f64 pow(f64 x, f64 y) { return powl(x,y); }


}