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
        glm::vec3 position{0.0f};
        glm::quat rotation{1.0f, 0.0f, 0.0f, 0.0f};
        glm::vec3 scale{1.0f};
    };

} // namespace Lila::ECS
