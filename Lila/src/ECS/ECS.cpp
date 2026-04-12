#include "ECS.h"

#include "Common/UUID.h"

namespace Lila::ECS {

    ECS::ECS() {
        componentManager_m.registerComponent<Tag>();
        componentManager_m.registerComponent<Transform>();
    }

    Entity ECS::createEntity() {
        const Entity entity = entityManager_m.createEntity();

        componentManager_m.addComponent(entity, Tag{
            Lila::UUID()
        });
        componentManager_m.addComponent(entity, Transform{
            glm::vec3(0, 0, 0),
            glm::quat(),
            glm::vec3(1, 1, 1)
        });

        return entity;
    }

    void ECS::destroyEntity(Entity entity) {
        entityManager_m.destroyEntity(entity);
    }

} // namespace Lila::ECS
