#pragma once

#include "platform/types.h"

#include "Camera.h"

#include "math/vec3.h"

namespace Lila {

class PerspectiveCamera : public Camera {
public:
    PerspectiveCamera(Vec3 position, Vec3 rotation) {}
    PerspectiveCamera(Vec3 position, Vec3 rotation, Vec3 scale) {}
    PerspectiveCamera(f32 fov, f32 aspectRatio, f32 near, f32 far);

    void changeProjection(f32 fov, f32 aspectRatio, f32 near, f32 far);

private:
    Vec3 position_m, rotation_m, scale_m;
};

} // namespace Lila
