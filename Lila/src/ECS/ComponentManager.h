#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

#include "Entity.h"
#include "SparseSet.h"
#include "Application/Application.h"

namespace Lila {
    class Application;
}

namespace Lila::ECS {

    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray : public IComponentArray {
    public:
        void insert(Entity entity, T component) { sparseSet.insert(entity, component); }
        void remove(Entity entity) { sparseSet.remove(entity); }
        T& get(Entity entity) { return sparseSet.get(entity); }
        bool has(Entity entity) { return sparseSet.contains(entity); }
        void entityDestroyed(Entity entity) override { if(has(entity)) remove(entity); }

    private:
        SparseSet<T> sparseSet;
    };

    class ComponentManager {
    public:
        template<typename T>
        void registerComponent() {
            componentArrays[typeid(T)] = std::make_shared<ComponentArray<T>>();
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeid(T)])->insert(entity, component);
        }

        template<typename T>
        T& getComponent(Entity entity) {
            return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeid(T)])->get(entity);
        }

        template<typename T>
        bool hasComponent(Entity entity) {
            return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeid(T)])->has(entity);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeid(T)])->remove(entity);
        }

        void entityDestroyed(Entity entity) {
            for (auto& [_, array] : componentArrays)
                array->entityDestroyed(entity);
        }

    private:
        std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> componentArrays;
    };

    ComponentManager& createComponentManager(Application& app);

} // namespace Lila::ECS
