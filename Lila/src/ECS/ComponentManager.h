#pragma once

#include <unordered_map>
#include <typeindex>

#include "Common/Pointers.h"
#include "Entity.h"
#include "SparseSet.h"

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
            componentArrays[typeid(T)] = shared<ComponentArray<T>>();
        }

        template<typename T>
        void addComponent(Entity entity, T component) {
            std::static_pointer_cast<ComponentArray<T>>(componentArrays.at(typeid(T)))->insert(entity, component);
        }

        template<typename T>
        T& getComponent(Entity entity) const {
            return std::static_pointer_cast<ComponentArray<T>>(componentArrays.at(typeid(T)))->get(entity);
        }

        template<typename T>
        bool hasComponent(Entity entity) const {
            return std::static_pointer_cast<ComponentArray<T>>(componentArrays.at(typeid(T)))->has(entity);
        }

        template<typename T>
        void removeComponent(Entity entity) {
            std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeid(T)])->remove(entity);
        }

        void entityDestroyed(Entity entity) {
            for (const Shared<IComponentArray>& array : componentArrays | std::views::values)
                array->entityDestroyed(entity);
        }

    private:
        std::unordered_map<std::type_index, Shared<IComponentArray>> componentArrays;
    };

} // namespace Lila::ECS
