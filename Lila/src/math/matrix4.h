#pragma once

#include "platform/types.h"

#include <array>

namespace Lila {
    
class Matrix4 {
public:
    Matrix4();

    Matrix4& identity();

    f32 get(u8 i, u8 j);
    Matrix4& set(u8 i, u8 j, f32 f);

    std::array<f32, 16> getEntries();

    Matrix4& add(Matrix4 matrix);
    Matrix4& sub(Matrix4 matrix);
    
    Matrix4& scalar(f32 scale);

    Matrix4& mul(const Matrix4& matrix);
    
    Matrix4& transpose();

    Matrix4& translate(f32 x, f32 y, f32 z);

    Matrix4& perspective(f32 fov, f32 aspectRatio, f32 near, f32 far);
    Matrix4& orthographic(f32 left, f32 right, f32 top, f32 bottom, f32 near, f32 far);

private:
    std::array<f32, 16> entries;
};
    
} // namespace Lila
