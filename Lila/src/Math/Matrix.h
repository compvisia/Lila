#pragma once

#include <cmath>
#include <array>

#include "Common/Types.h"

namespace Lila {

    // TODO: Make other more efficient classes for Matrix4 and Matrix3
    template <typename T, u8 Rows, u8 Columns>
    class alignas(16) Matrix {
    public:
        constexpr Matrix() = default;
        constexpr Matrix(std::array<T, Rows * Columns> data) : data_m(data) {}


        static constexpr Matrix identity() {
            std::array<T, Rows * Columns> identity{};

            for (size_t i = 0; i < Rows && i < Columns; ++i) {
                identity[i * Columns + i] = T(1);
            }

            return Matrix(identity);
        }

        Matrix<T, Rows, Columns> inverse() const {
            if(Rows != Columns)
                return Matrix();

            // TODO: Make an Inverse algorithm for NxN Matrices

            return Matrix();
        }

        T get(u8 row, u8 column) const {
            return data_m[row * Columns + column];
        }

        void set(u8 row, u8 column, T value) {
            data_m[row * Columns + column] = value;
        }

        Matrix<T, Rows, Columns> operator+(const Matrix<T, Rows, Columns>& other) const {
            Matrix result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] + other.data_m[i];

            return result;
        }
        Matrix<T, Rows, Columns> operator-(const Matrix<T, Rows, Columns>& other) const {
            Matrix result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] - other.data_m[i];

            return result;
        }
        Matrix<T, Rows, Columns> operator*(const Matrix<T, Rows, Columns>& other) const {
            Matrix result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] * other.data_m[i];

            return result;
        }
        Matrix<T, Rows, Columns> operator/(const Matrix<T, Rows, Columns>& other) const {
            Matrix result;

            for(u64 i = 0; i < data_m.size(); i++)
                result.data_m[i] = data_m[i] / other.data_m[i];

            return result;
        }

        Matrix<T, Rows, Columns>& operator+=(const Matrix<T, Rows, Columns>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] += other.data_m[i];

            return *this;
        }
        Matrix<T, Rows, Columns>& operator-=(const Matrix<T, Rows, Columns>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] -= other.data_m[i];

            return *this;
        }
        Matrix<T, Rows, Columns>& operator*=(const Matrix<T, Rows, Columns>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] *= other.data_m[i];

            return *this;
        }
        Matrix<T, Rows, Columns>& operator/=(const Matrix<T, Rows, Columns>& other) {
            for(u64 i = 0; i < data_m.size(); i++)
                data_m[i] /= other.data_m[i];

            return *this;
        }

    private:
        std::array<T, Rows * Columns> data_m{};
    };

    using Matrix4f = Matrix<f32, 4, 4>;
    using Matrix4d = Matrix<f64, 4, 4>;

} // namespace Lila
