#pragma once

#include "platform/types.h"

namespace Lila {
    
class Vec2 {
public:
    Vec2() { 
        x_m = y_m = 0;
    } 
    
    Vec2(f32 x, f32 y) {
        x_m = x;
        y_m = y;
    }

    void X(f32 x) { x_m = x; }
    void Y(f32 y) { y_m = y; }

    f32 x() { return x_m; }
    f32 y() { return y_m; }

    Vec2 operator+=(Vec2& vec) {
        x_m += vec.x();
        y_m += vec.y();
        return *this;
    }

    Vec2 operator-=(Vec2& vec) {
        x_m -= vec.x();
        y_m -= vec.y();
        return *this;
    }

    Vec2 operator*=(Vec2& vec) {
        x_m *= vec.x();
        y_m *= vec.y();
        return *this;
    }

    Vec2 operator/=(Vec2& vec) {
        x_m /= vec.x();
        y_m /= vec.y();
        return *this;
    }
    
private:
    f32 x_m, y_m;
};

inline bool operator==(Vec2& vec0, Vec2& vec1) {
    return vec0.x() == vec1.x() && vec0.y() == vec1.y();
}

inline bool operator!=(Vec2& vec0, Vec2& vec1) {
    return !(vec0 == vec1);
}


inline Vec2 operator+(Vec2& vec0, Vec2& vec1) {
    return vec0 += vec1;
}

inline Vec2 operator-(Vec2& vec0, Vec2& vec1) {
    return vec0 -= vec1;
}

inline Vec2 operator*(Vec2& vec0, Vec2& vec1) {
    return vec0 *= vec1;
}

inline Vec2 operator/(Vec2& vec0, Vec2& vec1) {
    return vec0 /= vec1;
}

} // namespace Lila