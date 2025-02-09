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

    Vec3 operator+=(Vec3& vec) {
        x_m += vec.x();
        y_m += vec.y();
        z_m += vec.z();
        return *this;
    }

    Vec3 operator-=(Vec3& vec) {
        x_m -= vec.x();
        y_m -= vec.y();
        z_m -= vec.z();
        return *this;
    }

    Vec3 operator*=(Vec3& vec) {
        x_m *= vec.x();
        y_m *= vec.y();
        z_m *= vec.z();
        return *this;
    }

    Vec3 operator/=(Vec3& vec) {
        x_m /= vec.x();
        y_m /= vec.y();
        z_m /= vec.z();
        return *this;
    }
    
private:
    f32 x_m, y_m, z_m;
};

inline bool operator==(Vec3& vec0, Vec3& vec1) {
    return vec0.x() == vec1.x() && vec0.y() == vec1.y() && vec0.z() == vec1.z();
}

inline bool operator!=(Vec3& vec0, Vec3& vec1) {
    return !(vec0 == vec1);
}


inline Vec3 operator+(Vec3& vec0, Vec3& vec1) {
    return vec0 += vec1;
}

inline Vec3 operator-(Vec3& vec0, Vec3& vec1) {
    return vec0 -= vec1;
}

inline Vec3 operator*(Vec3& vec0, Vec3& vec1) {
    return vec0 *= vec1;
}

inline Vec3 operator/(Vec3& vec0, Vec3& vec1) {
    return vec0 /= vec1;
}

} // namespace Lila