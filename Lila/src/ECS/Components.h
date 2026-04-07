#pragma once

#include <bitset>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Common/UUID.h"

namespace Lila::ECS {

    constexpr size_t MAX_COMPONENTS = 64;
    using ComponentSignature = std::bitset<MAX_COMPONENTS>;

    struct Tag {
        Lila::UUID uuid;
    };

    struct Transform {
        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scalar;
    };

} // namespace Lila::ECS
