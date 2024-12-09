#pragma once

#include "math/matrix4.h"
#include "math/vec3.h"

namespace Lila {

class Camera {
public:
    Camera() = default;
    virtual ~Camera() = default;

    const Matrix4& getProjection() {
        return projection_m;
    }

    const Vec3& getPosition() {
        return position_m;
    }

    const Vec3& getRotation() {
        return rotation_m;
    }

    const Vec3& getScale() {
        return scale_m;
    }

protected:
    Matrix4 projection_m;
    Vec3 position_m, rotation_m, scale_m;
};

} // namespace Lila
