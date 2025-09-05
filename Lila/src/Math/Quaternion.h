#pragma once

#include <math.h>

#include "Common/Types.h"

#include "Vec3.h"

namespace Lila {

    template<typename T>
    class alignas(16) Quaternion {
    public:
        Quaternion() : w(1), x(0), y(0), z(0) {}
        Quaternion(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}

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
                cr * cp * cy + sr * sp * sy, // w
                sr * cp * cy - cr * sp * sy, // x
                cr * sp * cy + sr * cp * sy, // y
                cr * cp * sy - sr * sp * cy  // z
            );
        }

        static T dot(const Quaternion& a, const Quaternion& b) {
            return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
        }

        T dot(const Quaternion& other) const {
            return w*other.w + x*other.x + y*other.y + z*other.z;
        }

        T magnitude() const {
            return sqrt(w * w + x * x + y * y + z * z);
        }

        Quaternion<T> normalized() const {
            T mag = magnitude();
            return Quaternion(w / mag, x / mag, y / mag, z / mag);
        }

        Quaternion<T> conjugate() const {
            return Quaternion(w, -x, -y, -z);
        }

        Quaternion<T> inverse() const {
            T mag = magnitude();
            return Quaternion(w / mag, -x / mag, -y / mag, -z / mag);
        }


        Quaternion<T> operator+(const Quaternion<T>& other) const {
            return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
        }
        Quaternion<T> operator-(const Quaternion<T>& other) const {
            return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
        }
        Quaternion<T> operator*(const Quaternion<T>& other) const {
            return Quaternion(
                w * other.w - x * other.x - y * other.y - z * other.z,
                w * other.x + x * other.w + y * other.z - z * other.y,
                w * other.y - x * other.z + y * other.w + z * other.x,
                w * other.z + x * other.y - y * other.x + z * other.w
            );
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
            w = (w * other.w - x * other.x - y * other.y - z * other.z);
            x = (w * other.x + x * other.w + y * other.z - z * other.y);
            y = (w * other.y - x * other.z + y * other.w + z * other.x);
            z = (w * other.z + x * other.y - y * other.x + z * other.w);

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
                euler.y = std::copysign(M_PI / 2, siny);
            else
                euler.y = std::asin(siny);

            T sinr = T(2) * (w*z + x*y);
            T cosr = T(1) - T(2) * (y*y + z*z);
            euler.z = std::atan2(sinr, cosr);

            return euler;
        }

    public:
        T w, x, y, z;
    };

    using Quaternionf = Quaternion<f32>;
    using Quaterniond = Quaternion<f64>;

} // namespace Lila
