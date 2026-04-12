#pragma once

#include <glm/mat4x4.hpp>

#include "Renderer/Window.h"

#include "Common/Types.h"

namespace Lila {

    enum class CameraType : u8 {
        None = 0,
        Perspective,
        Orthographic
    };

    struct CameraComponent {
        CameraType type = CameraType::Perspective;
        f32 fov = 110.0f; // INFO: Value is in degrees (only used for CameraType::Perspective)

        f32 near = 0.1f;
        f32 far = 100.0f;
    };

    glm::mat4 getProjection(const CameraComponent& camera, const Window& window);

} // namespace Lila
