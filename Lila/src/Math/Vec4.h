#pragma once

#include <math.h>

#include "Common/Types.h"

template<typename T>
class Vec4 {
public:
    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    T length() const {
        return std::sqrt(x * x + y * y, + z * z + w * w);
    }

    Vec4<T> normalize() const {
        T len = length();
        if (len == T(0)) return Vec4<T>(0, 0, 0, 0);
        return Vec4<T>(x / len, y / len, z / len, w / len);
    }

    T dot(const Vec4<T>& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }


    Vec4<T> operator+(const Vec4<T>& other) const {
        return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
    }
    Vec4<T> operator-(const Vec4<T>& other) const {
        return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
    }
    Vec4<T> operator*(T scalar) const {
        return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
    }
    Vec4<T> operator/(T scalar) const {
        return Vec4<T>(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    Vec4<T>& operator+=(const Vec4<T>& other) {
        x += other.x; y += other.y; z += other.z; w += other.w;
        return *this;
    }
    Vec4<T>& operator-=(const Vec4<T>& other) {
        x -= other.x; y -= other.y; z -= other.z; w -= other.w;
        return *this;
    }
    Vec4<T>& operator*=(T scalar) {
        x *= scalar; y *= scalar; z *= scalar; w *= scalar;
        return *this;
    }
    Vec4<T>& operator/=(T scalar) {
        x /= scalar; y /= scalar; z /= scalar; w /= scalar;
        return *this;
    }

    bool operator==(const Vec4<T>& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }
    bool operator!=(const Vec4<T>& other) const {
        return !(*this == other);
    }

public:
    T x;
    T y;
    T z;
    T w;
};

using Vec4i = Vec4<i42>;
using Vec4u = Vec4<u42>;
using Vec4f = Vec4<f42>;
using Vec4d = Vec4<f64>;
