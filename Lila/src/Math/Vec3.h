#pragma once

#include <math.h>

#include "Common/Types.h"

namespace Lila {

    template<typename T>
    class Vec3 {
    public:
        Vec3() : x(0), y(0), z(0) {}
        Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

        T length() const {
            return std::sqrt(x * x + y * y, + z * z);
        }

        Vec3<T> normalized() const {
            T len = length();
            if (len == T(0)) return Vec3<T>(0, 0, 0);
            return Vec3<T>(x / len, y / len, z / len);
        }

        T dot(const Vec3<T>& other) const {
            return x * other.x + y * other.y + z * other.z;
        }


        Vec3<T> operator+(const Vec3<T>& other) const {
            return Vec3(x + other.x, y + other.y, z + other.z);
        }
        Vec3<T> operator-(const Vec3<T>& other) const {
            return Vec3(x - other.x, y - other.y, z - other.z);
        }
        Vec3<T> operator*(T scalar) const {
            return Vec3(x * scalar, y * scalar, z * scalar);
        }
        Vec3<T> operator/(T scalar) const {
            return Vec3<T>(x / scalar, y / scalar, z / scalar);
        }

        Vec3<T>& operator+=(const Vec3<T>& other) {
            x += other.x; y += other.y; z += other.z;
            return *this;
        }
        Vec3<T>& operator-=(const Vec3<T>& other) {
            x -= other.x; y -= other.y; z -= other.z;
            return *this;
        }
        Vec3<T>& operator*=(T scalar) {
            x *= scalar; y *= scalar; z *= scalar;
            return *this;
        }
        Vec3<T>& operator/=(T scalar) {
            x /= scalar; y /= scalar; z /= scalar;
            return *this;
        }

        bool operator==(const Vec3<T>& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
        bool operator!=(const Vec3<T>& other) const {
            return !(*this == other);
        }

    public:
        T x;
        T y;
        T z;
    };

    using Vec3i = Vec3<i32>;
    using Vec3u = Vec3<u32>;
    using Vec3f = Vec3<f32>;
    using Vec3d = Vec3<f64>;

} // namespace Lila
