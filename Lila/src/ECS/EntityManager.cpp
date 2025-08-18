#include "EntityManager.h"

namespace Lila::ECS {


    Entity EntityManager::createEntity() {
        Entity e = nextEntity++;
        signatures[e] = {};
        aliveEntities.push_back(e);
        return e;
    }

    void EntityManager::destroyEntity(Entity e) {
        // remove from aliveEntities
            aliveEntities.erase(
                std::remove(aliveEntities.begin(), aliveEntities.end(), e),
                aliveEntities.end()
            );

            // remove signature
            signatures.erase(e);
    }

    const std::vector<Entity>& EntityManager::getAliveEntities() const {
        return aliveEntities;
    }

    void EntityManager::setSignature(Entity e, ComponentSignature sig) {
        signatures[e] = sig;
    }

    ComponentSignature EntityManager::getSignature(Entity e) const {
        return signatures.at(e);
    }

} // namespace Lila::ECS
