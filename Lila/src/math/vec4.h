#pragma once

#include "platform/types.h"

namespace Lila {
    
class Vec4 {
public:
    Vec4() { 
        x_m = y_m = z_m = w_m = 0;
    } 
    
    Vec4(f32 x, f32 y, f32 z, f32 w) {
        x_m = x;
        y_m = y;
        z_m = z;
        w_m = w;
    }

    void X(f32 x) { x_m = x; }
    void Y(f32 y) { y_m = y; }
    void Z(f32 z) { z_m = z; }
    void W(f32 w) { w_m = w; }

    f32 x() { return x_m; }
    f32 y() { return y_m; }
    f32 z() { return z_m; }
    f32 w() { return w_m; }

    Vec4 operator+=(Vec4& vec) {
        x_m += vec.x();
        y_m += vec.y();
        z_m += vec.z();
        w_m *= vec.w();
        return *this;
    }

    Vec4 operator-=(Vec4& vec) {
        x_m -= vec.x();
        y_m -= vec.y();
        z_m -= vec.z();
        w_m *= vec.w();
        return *this;
    }

    Vec4 operator*=(Vec4& vec) {
        x_m *= vec.x();
        y_m *= vec.y();
        z_m *= vec.z();
        w_m *= vec.w();
        return *this;
    }

    Vec4 operator/=(Vec4& vec) {
        x_m /= vec.x();
        y_m /= vec.y();
        z_m /= vec.z();
        w_m /= vec.w();
        return *this;
    }
    
private:
    f32 x_m, y_m, z_m, w_m;
};

inline bool operator==(Vec4& vec0, Vec4& vec1) {
    return vec0.x() == vec1.x() && vec0.y() == vec1.y() && vec0.z() == vec1.z();
}

inline bool operator!=(Vec4& vec0, Vec4& vec1) {
    return !(vec0 == vec1);
}


inline Vec4 operator+(Vec4& vec0, Vec4& vec1) {
    return vec0 += vec1;
}

inline Vec4 operator-(Vec4& vec0, Vec4& vec1) {
    return vec0 -= vec1;
}

inline Vec4 operator*(Vec4& vec0, Vec4& vec1) {
    return vec0 *= vec1;
}

inline Vec4 operator/(Vec4& vec0, Vec4& vec1) {
    return vec0 /= vec1;
}

} // namespace Lila