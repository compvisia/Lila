#pragma once

#include <glm/mat4x4.hpp>

#include "Camera.h"
#include "ECS/Components.h"

namespace Lila {

    glm::mat4 getModelMatrix(const Lila::ECS::Transform& transform);

    glm::mat4 getViewMatrix(const Lila::ECS::Transform& transform);

    glm::mat4 getProjectionMatrix(const CameraComponent& camera, const Window& window);

} // namespace Lila
