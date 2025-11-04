#pragma once

#include <vector>
#include <unordered_map>

#include "Entity.h"
#include "Components.h"

namespace Lila::ECS {

    class EntityManager {
    public:
        Entity createEntity();

        void destroyEntity(Entity e);

        const std::vector<Entity>& getAliveEntities() const;

        void setSignature(Entity e, ComponentSignature sig);
        ComponentSignature getSignature(Entity e) const;

    private:
        Entity nextEntity = 0;
        std::vector<Entity> aliveEntities;
        std::unordered_map<Entity, ComponentSignature> signatures;
    };

} // namespace Lila::ECS
