#pragma once

#include "Entity.h"
#include "Components.h"
#include "EntityManager.h"
#include "ComponentManager.h"

namespace Lila::ECS {

    class ECS {
    public:
        ECS();

        ECS(const ECS& other) = delete;
        ECS& operator=(const ECS& other) = delete;

        ECS(ECS&& other) noexcept = delete;
        ECS& operator=(ECS&& other) noexcept = delete;

        ~ECS();

        Entity createEntity();
        void destroyEntity(Entity entity);

        const std::vector<Entity>& getAliveEntities() const {
            return entityManager_m.getAliveEntities();
        }

    public:
        template<typename T>
        void registerComponent() {
            componentManager_m.registerComponent<T>();
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            componentManager_m.addComponent<T>(entity, component);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            componentManager_m.removeComponent<T>(entity);
        }

        template<typename T>
        T& getComponent(Entity entity) const {
            return componentManager_m.getComponent<T>(entity);
        }

        template<typename T>
        bool hasComponent(Entity entity) const {
            return componentManager_m.hasComponent<T>(entity);
        }

    private:
        EntityManager entityManager_m;
        ComponentManager componentManager_m;
    };

} // namespace Lila::ECS
