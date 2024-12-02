#pragma once

#include "platform/types.h"

namespace Lila {
    
class Vec3 {
public:
    Vec3() { 
        x_m = y_m = z_m = 0;
    } 
    
    Vec3(f32 x, f32 y, f32 z) {
        x_m = x;
        y_m = y;
        z_m = z;
    }

    void X(f32 x) { x_m = x; }
    void Y(f32 y) { y_m = y; }
    void Z(f32 z) { z_m = z; }

    f32 x() { return x_m; }
    f32 y() { return y_m; }
    f32 z() { return z_m; }

private:
    f32 x_m, y_m, z_m;
};

} // namespace Lila