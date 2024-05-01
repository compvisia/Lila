#include "Math.h"

#include <math.h>

namespace Lila {

	double toRadians(double degrees) { return degrees * RadiansMul; }
	double toDegrees(double radians) { return radians * DegreesMul; }
	double toGradians(double degrees) { return degrees * GradiansMul; }


	double sin(double x) { return sinl(x); }
	double cos(double x) { return cosl(x); }
	double tan(double x) { return tanl(x); }

	double asin(double x) { return asinl(x); }
	double acos(double x) { return acosl(x); }
	double atan(double x) { return atanl(x); }

	double pythagoras(double a, double b) { return a * a + b * b; }
	double sqrtPythagoras(double a, double b) { return sqrtl(a * a + b * b); }

	double sqrt(double v) { return sqrtl(v); }

	double abs(double v) { return fabs(v); }

	double floor(double v) { return floorl(v); }
	double ceil(double v) { return ceill(v); }
	double round(double v) { return roundl(v); }
	
	double log(double v) { return logl(v); }
	double log2(double v) { return log2l(v); }
	
	double pow(double x, double y) { return powl(x,y); }


}