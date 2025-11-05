#include "Camera.h"

#include <glm/ext/matrix_clip_space.hpp>

namespace Lila {

    glm::mat4 getProjection(const CameraComponent& camera, const Window& window) {
        if(camera.type == CameraType::Perspective) {
            const f32 fovRad = glm::radians(camera.fov);

            return glm::perspective(
                fovRad,
                static_cast<f32>(window.getWidth())/window.getHeight(),
                camera.near,
                camera.far
            );
        }

        return glm::ortho(
            0.0f,
            static_cast<f32>(window.getWidth()),
            static_cast<f32>(window.getHeight()),
            0.0f,
            camera.near,
            camera.far
        );
    }

} // namespace Lila
