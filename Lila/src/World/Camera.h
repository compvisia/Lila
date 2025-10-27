#pragma once

#include <glm/mat4x4.hpp>

#include "Common/Types.h"

namespace Lila {

    enum class CameraType {
        Perspective,
        Orthographic
    };

    struct CameraComponent {
        CameraType type = CameraType::Perspective;
        f32 fov = 110.0f; // Degrees, only used for Perspective

        f32 near = 0.1f;
        f32 far = 100.0f;
    };

    glm::mat4 getProjection(const CameraComponent& camera);

} // namespace Lila
