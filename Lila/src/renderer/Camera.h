#pragma once

#include "math/matrix4.h"

namespace Lila {

class Camera {
public:
    Camera() = default;
    virtual ~Camera() = default;

    const Matrix4& getProjection() {
        return projection_m;
    }

protected:
    Matrix4 projection_m;
};

} // namespace Lila
