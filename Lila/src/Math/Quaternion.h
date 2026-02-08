#pragma once

#include <cmath>
#include <numbers>

#include "Common/Types.h"

#include "Vec3.h"

namespace Lila {

    template<typename T>
    class alignas(16) Quaternion {
    public:
        constexpr Quaternion() : w(1), x(0), y(0), z(0) {}
        constexpr Quaternion(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}

        static constexpr Quaternion identity() {
            return Quaternion(1, 0, 0, 0);
        }

        static Quaternion fromEuler(T pitch, T yaw, T roll) {
            T cy = std::cos(yaw * T(0.5));
            T sy = std::sin(yaw * T(0.5));
            T cp = std::cos(pitch * T(0.5));
            T sp = std::sin(pitch * T(0.5));
            T cr = std::cos(roll * T(0.5));
            T sr = std::sin(roll * T(0.5));

            return Quaternion(
                cr * cp * cy + sr * sp * sy,
                sr * cp * cy - cr * sp * sy,
                cr * sp * cy + sr * cp * sy,
                cr * cp * sy - sr * sp * cy
            );
        }

        static T dot(const Quaternion& a, const Quaternion& b) {
            return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
        }

        T dot(const Quaternion& other) const {
            return w*other.w + x*other.x + y*other.y + z*other.z;
        }

        T norm() const {
            return std::sqrt(w * w + x * x + y * y + z * z);
        }

        Quaternion<T> normalized() const {
            T norm = norm();

            if(norm == T(0))
                return Quaternion();

            return Quaternion(w / norm, x / norm, y / norm, z / norm);
        }

        Quaternion<T> conjugate() const {
            return Quaternion(w, -x, -y, -z);
        }

        Quaternion<T> inverse() const {
            T norm = w * w + x * x + y * y + z * z;

            if (norm == T(0))
                return Quaternion();

            return conjugate() / norm;
        }


        Quaternion<T> operator+(const Quaternion<T>& other) const {
            return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
        }
        Quaternion<T> operator-(const Quaternion<T>& other) const {
            return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
        }
        Quaternion<T> operator*(const Quaternion<T>& other) const {
            return Quaternion(
                w * other.w - x * other.x - y * other.y - z * other.z,
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            );
        }
        Quaternion<T> operator/(T scalar) const {
            return Quaternion(w / scalar, x / scalar, y / scalar, z / scalar);
        }

        Quaternion<T>& operator+=(const Quaternion<T>& other) {
            x += other.x; y += other.y; z += other.z; w += other.w;
            return *this;
        }
        Quaternion<T>& operator-=(const Quaternion<T>& other) {
            x -= other.x; y -= other.y; z -= other.z; w -= other.w;
            return *this;
        }
        Quaternion<T>& operator*=(const Quaternion<T>& other) {
            const T nw = w * other.w - x * other.x - y * other.y - z * other.z;
            const T nx = w * other.x + x * other.w + y * other.z - z * other.y;
            const T ny = w * other.y - x * other.z + y * other.w + z * other.x;
            const T nz = w * other.z + x * other.y - y * other.x + z * other.w;
            w = nw; x = nx; y = ny; z = nz;

            return *this;
        }
        Quaternion<T> operator/=(T scalar) {
            w /= scalar;
            x /= scalar;
            y /= scalar;
            z /= scalar;

            return *this;
        }

        bool operator==(const Quaternion<T>& other) const {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }
        bool operator!=(const Quaternion<T>& other) const {
            return !(*this == other);
        }

        Vec3<T> toEuler() const {
            Vec3<T> euler;

            T sinp = T(2) * (w*x + y*z);
            T cosp = T(1) - T(2) * (x*x + y*y);
            euler.x = std::atan2(sinp, cosp);
            T siny = T(2) * (w*y - z*x);
            if (std::abs(siny) >= 1)
                euler.y = std::copysign(std::numbers::pi / 2, siny);
            else
                euler.y = std::asin(siny);

            T sinr = T(2) * (w*z + x*y);
            T cosr = T(1) - T(2) * (y*y + z*z);
            euler.z = std::atan2(sinr, cosr);

            return euler;
        }

    public:
        T w = 1, x = 0, y = 0, z = 0;
    };

    using Quaternionf = Quaternion<f32>;
    using Quaterniond = Quaternion<f64>;

} // namespace Lila
