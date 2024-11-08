#include "math.h"

namespace Lila {
    
f32 rad32(f32 deg) {
    return deg * DEG_TO_RAD;
}

f64 rad64(f64 deg) {
    return deg * DEG_TO_RAD;
}

f32 rad32G(f32 grad) {
    return grad * GRAD_TO_RAD;
}

f32 rad32T(f32 turn) {
    return turn * TURN_TO_RAD;
}

f32 deg32(f32 rad) {
    return rad * RAD_TO_DEG;
}

f64 deg64(f64 rad) {
    return rad * RAD_TO_DEG;
}

f32 deg32G(f32 grad) {
    return grad * GRAD_TO_DEG;
}

f32 deg32T(f32 turn) {
    return TURN_TO_DEG;
}

f32 grad32D(f32 deg) {
    return deg * DEG_TO_GRAD;
}

f32 grad32R(f32 rad) {
    return rad * RAD_TO_GRAD;
}

f32 grad32T(f32 turn) {
    return TURN_TO_GRAD;
}

f32 turn32R(f32 rad) {
    return rad * RAD_TO_TURN;
}

f32 turn32D(f32 deg) {
    return deg * DEG_TO_TURN;
}

f32 turn32G(f32 grad) {
    return grad * GRAD_TO_TURN;
}

} // namespace Lila