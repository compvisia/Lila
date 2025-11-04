#pragma once

#include <cmath>
#include <array>

#include "Common/Types.h"

namespace Lila {

    template <typename T>
    class alignas(16) Matrix4 {
    public:
        constexpr Matrix4() = default;
        constexpr Matrix4(std::array<T, 16> data) : data_m(data) {}

        static constexpr Matrix4 identity() {
            std::array<T, 16> identity{};

            for (size_t i = 0; i < 4 && i < 4; ++i) {
                identity[i * 4 + i] = T(1);
            }

            return Matrix4(identity);
        }

        Matrix4<T> inverse() const {
            // TODO: Make an Inverse algorithm for NxN Matrices

            return Matrix4();
        }

        T get(u8 row, u8 column) const {
            return data_m[row * 4 + column];
        }

        void set(u8 row, u8 column, T value) {
            data_m[row * 4 + column] = value;
        }

        Matrix4<T> operator+(const Matrix4<T>& other) const {
            Matrix4 result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] + other.data_m[i];

            return result;
        }
        Matrix4<T> operator-(const Matrix4<T>& other) const {
            Matrix4 result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] - other.data_m[i];

            return result;
        }
        Matrix4<T> operator*(const Matrix4<T>& other) const {
            Matrix4 result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] * other.data_m[i];

            return result;
        }
        Matrix4<T> operator/(const Matrix4<T>& other) const {
            Matrix4 result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] / other.data_m[i];

            return result;
        }

        Matrix4<T>& operator+=(const Matrix4<T>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] += other.data_m[i];

            return *this;
        }
        Matrix4<T>& operator-=(const Matrix4<T>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] -= other.data_m[i];

            return *this;
        }
        Matrix4<T>& operator*=(const Matrix4<T>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] *= other.data_m[i];

            return *this;
        }
        Matrix4<T>& operator/=(const Matrix4<T>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] /= other.data_m[i];

            return *this;
        }

    private:
        std::array<T, 16> data_m{0};
    };

    using Matrix4f = Matrix4<f32>;
    using Matrix4d = Matrix4<f64>;

} // namespace Lila
