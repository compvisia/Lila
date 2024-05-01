#pragma once

#include "Quaternion.h"
#include "Vectors.h"
#include "Matrices.h"

#define Pi           3.14159265358979323846f     // π
#define HalfPi       1.57079632679489661923f     // π / 2
#define QuarterPi    0.78539816339744830962f     // π / 4
#define OneOverPi    0.31830988618379067154f     // 1 / π
#define Tau          6.28318530717958647692f     // 2 * π
/*                   -----------------------     */
#define SqrtOf2      1.41421356237309504880f     // √2
#define SqrtOf3      1.73205080756887729352f     // √3
#define SqrtOf4      2.00000000000000000000f     // √4
#define SqrtOf5      2.23606797749978969640f     // √5
#define SqrtOf6      2.44948974278317809820f     // √6
#define SqrtOf7      2.64575131106459059050f     // √7
#define SqrtOf8      2.82842712474619009760f     // √8
#define SqrtOf9      3.00000000000000000000f     // √9
#define SqrtOf10     3.16227766016837933200f     // √10
/*                   -----------------------     */
#define GoldenRatio  1.61803398874989484820f     // (1 + √5) / 2
#define SilverRatio  2.41421356237309504880f     //  1 + √2
/*                   -----------------------     */
#define RadiansMul   0.01745329251994329577f     // π / 180
#define DegreesMul   57.2957795130823208768f     // 180 / π
#define GradiansMul  1.11111111111111111111f     // 10 / 9
/*                   -----------------------     */
#define Giga         1000000000.00000000000f     // 1 * 1 000 000 000
#define Mega         1000000.00000000000000f     // 1 * 1 000 000
#define Kilo         1000.00000000000000000f     // 1 * 1 000
/*                   -----------------------     */
#define Milli        0.00100000000000000000f     // 1 / 1 000
#define Micro        0.00000100000000000000f     // 1 / 1 000 000
#define Nano         0.00000000100000000000f     // 1 / 1 000 000 000
/*                   -----------------------     */
#define Inf          1e30f                       // 1 * 10 ^ 30
/*                   -----------------------     */
#define FloatEpsilon 0.00000011920928960000f     // 1 + FloatEpsilon != 0 && FloatEpsilon == 0.

#define InvGiga Nano
#define InvMega Micro
#define InvKilo Milli

#define InvMilli Kilo
#define InvMicro Mega
#define InvNano  Giga

namespace Lila {

	double toRadians(double degrees);
	double toDegrees(double radians);
	double toGradians(double degrees);

	
	double sin(double x);
	double cos(double x);
	double tan(double x);
	
	double asin(double x);
	double acos(double x);
	double atan(double x);

	double pythagoras(double a, double b);
	double sqrtPythagoras(double a, double b);

	double sqrt(double v);

	double abs(double v);

	double floor(double v);
	double ceil(double v);
	double round(double v);
	
	double log(double v);
	double log2(double v);

	double pow(double x, double y);

}