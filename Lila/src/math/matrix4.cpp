#include "matrix4.h"

#include "math/math.h"

namespace Lila {
    
Matrix4::Matrix4() {
    identity();
}

Matrix4& Matrix4::identity() {
    entries.fill(0);
     set(0, 0, 1.0f)
    .set(1, 1, 1.0f)
    .set(2, 2, 1.0f)
    .set(3, 3, 1.0f);
}

f32 Matrix4::get(u8 i, u8 j) {
    return entries.at(i + j * 4);
}

Matrix4& Matrix4::set(u8 i, u8 j, f32 f) {
    entries.at(i + j * 4) = f;
    return *this;
}

std::array<f32, 16> Matrix4::getEntries() {
    return entries;
}

Matrix4& Matrix4::add(Matrix4 matrix) {
    for(u8 i = 0; i < 16; i++)
        entries.at(i) += matrix.getEntries().at(i);

    return *this;
}

Matrix4& Matrix4::sub(Matrix4 matrix) {
    add(matrix.scalar(-1.0f));

    return *this;
}

Matrix4& Matrix4::scalar(f32 scale) {
    for(u8 i = 0; i < 16; i++)
        entries.at(i) *= scale;

    return *this;
}

Matrix4& Matrix4::mul(const Matrix4& matrix) {
    return *this;
}

Matrix4& Matrix4::transpose() {
    return *this;
}

Matrix4& Matrix4::translate(f32 x, f32 y, f32 z) {
    identity();

    set(0, 3, x);
    set(1, 3, y);
    set(2, 3, z);
    
    return *this;
}

Matrix4& Matrix4::perspective(f32 fov, f32 aspectRatio, f32 near, f32 far) {
    identity();

    f32 tanHalfFov = tan(rad32(fov)/2.0f);

    set(0, 0, 1.0f / (aspectRatio * tanHalfFov));
    set(1, 1, 1.0f / tanHalfFov);
    set(2, 2, -((far + near)/(far - near)));
    set(3, 2, -((2 * far * near)/(far - near)));
    set(2, 3, -1.0f);
    set(3, 3, 0.0f);

    return *this;
}

Matrix4& Matrix4::orthographic(f32 left, f32 right, f32 top, f32 bottom, f32 near, f32 far) {
    identity();

    set(0, 0, (right - left) / 2.0f);
    set(3, 0, (right + left) / 2.0f);
    set(1, 1, (top - bottom) / 2.0f);
    set(3, 1, (top + bottom) / 2.0f);
    set(2, 2, (far - near) / 2.0f);
    set(3, 2, -((far + near) / 2.0f));

    return *this;
}

} // namespace Lila
