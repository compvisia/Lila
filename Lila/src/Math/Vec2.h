#pragma once

#include <cmath>

#include "Common/Types.h"

namespace Lila {

    template<typename T>
    class Vec2 {
    public:
        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}

        T length() const {
            return std::sqrt(x * x + y * y);
        }

        Vec2<T> normalized() const {
            T len = length();
            if (len == T(0)) return Vec2<T>(0, 0, 0);
            return Vec2<T>(x / len, y / len);
        }

        T dot(const Vec2<T>& other) const {
            return x * other.x + y * other.y;
        }


        Vec2<T> operator+(const Vec2<T>& other) const {
            return Vec2(x + other.x, y + other.y);
        }
        Vec2<T> operator-(const Vec2<T>& other) const {
            return Vec2(x - other.x, y - other.y);
        }
        Vec2<T> operator*(T scalar) const {
            return Vec2(x * scalar, y * scalar);
        }
        Vec2<T> operator/(T scalar) const {
            return Vec2<T>(x / scalar, y / scalar);
        }

        Vec2<T>& operator+=(const Vec2<T>& other) {
            x += other.x; y += other.y;
            return *this;
        }
        Vec2<T>& operator-=(const Vec2<T>& other) {
            x -= other.x; y -= other.y;
            return *this;
        }
        Vec2<T>& operator*=(T scalar) {
            x *= scalar; y *= scalar;
            return *this;
        }
        Vec2<T>& operator/=(T scalar) {
            x /= scalar; y /= scalar;
            return *this;
        }

        bool operator==(const Vec2<T>& other) const {
            return x == other.x && y == other.y;
        }
        bool operator!=(const Vec2<T>& other) const {
            return !(*this == other);
        }

    public:
        T x;
        T y;
    };

    using Vec2i = Vec2<i32>;
    using Vec2u = Vec2<u32>;
    using Vec2f = Vec2<f32>;
    using Vec2d = Vec2<f64>;

} // namespace Lila
