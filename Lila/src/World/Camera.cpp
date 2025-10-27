#include "Camera.h"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

namespace Lila {

    glm::mat4 getProjection(const CameraComponent& camera) {
        if(camera.type == CameraType::Perspective) {
            f32 fovRad = glm::radians(camera.fov);

            return glm::perspective(fovRad, 16.0f/9.0f, camera.near, camera.far);
        }

        return glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, camera.near, camera.far);
    }

} // namespace Lila
