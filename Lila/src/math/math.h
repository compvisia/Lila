#pragma once

#include "platform/types.h"

#include <math.h>

#define PI             3.14159265358979323846f
#define HALF_PI        1.57079632679489661923f
#define QUARTER_PI     0.78539816339744830962f
#define ONE_OVER_PI    0.31830988618379067154f
#define TAU            6.28318530717958647692f

#define SQRT_OF_2      1.41421356237309504880f
#define SQRT_OF_3      1.73205080756887729352f
#define SQRT_OF_4      2.0f
#define SQRT_OF_5      2.23606797749978969640f
#define SQRT_OF_6      2.44948974278317809820f
#define SQRT_OF_7      2.64575131106459059050f
#define SQRT_OF_8      2.82842712474619009760f
#define SQRT_OF_9      3.0f
#define SQRT_OF_10     3.16227766016837933200f

#define GOLDEN_RATIO  1.61803398874989484820f
#define SILVER_RATIO  2.41421356237309504880f

#define RAD_TO_DEG   57.2957795130823208768f
#define RAD_TO_GRAD  63.6619772367581343075f
#define RAD_TO_TURN  0.15915494309189533577f

#define DEG_TO_RAD   0.01745329251994329577f
#define DEG_TO_GRAD  1.11111111111111111111f
#define DEG_TO_TURN  0.00277777777777777777f

#define GRAD_TO_DEG  0.9f
#define GRAD_TO_RAD  0.01570796326794896619f
#define GRAD_TO_TURN 0.0025f

#define TURN_TO_DEG  360.f
#define TURN_TO_RAD  TAU
#define TURN_TO_GRAD 400.0f

namespace Lila {
    
f32 rad32(f32 deg);
f64 rad64(f64 deg);
f32 rad32G(f32 grad);
f32 rad32T(f32 turn);

f32 deg32(f32 rad);
f64 deg64(f64 rad);
f32 deg32G(f32 grad);
f32 deg32T(f32 turn);

f32 grad32R(f32 rad);
f32 grad32D(f32 deg);
f32 grad32T(f32 turn);

f32 turn32R(f32 rad);
f32 turn32D(f32 deg);
f32 turn32G(f32 grad);

} // namespace Lila
 