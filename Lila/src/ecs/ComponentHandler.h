#pragma once

#include "platform/types.h"

#include "Component.h"
#include "ComponentPool.h"

#include <typeinfo>

namespace Lila {
class ComponentHandler {
public:
    template<typename T>
    void registerComponent() {
        u32 type = typeid(T).hash_code();

        ASSERT(componentTypes_m.find(type) == componentTypes_m.end(), "Cannot register a component more than once!");
        ASSERT(registeredComponents_m < 512, "Too many registered components!")

        componentTypes_m.insert({ type, registeredComponents_m });
        componentPools_m.insert({ type, shared<ComponentPool<T>>() });
        registeredComponents_m++;
    };

    template<typename T>
    u16 getComponentType() {
        u32 type = typeid(T).hash_code();

        ASSERT(componentTypes_m.find(type) != componentTypes_m.end(), "Cannot use unregistered component!");

        return componentTypes_m[type];
    };

    template<typename T>
    void addComponent(u64 entity, Shared<T> component) {
        getComponentPool<T>()->addComponent(entity, component);
    };

    template<typename T>
    void removeComponent(u64 entity) {
        getComponentPool<T>()->removeComponent(entity);
    };

    template<typename T>
    Shared<T> getComponent(u64 entity) {
        return getComponentPool<T>()->getComponent(entity);
    };

    void entityDestroyed(u64 entity) {
        for (auto const& pair : componentPools_m) {
            auto const& component = pair.second;
            component->entityDestroyed(entity);
        }
    };

private:
    template<typename T>
    Shared<ComponentPool<T>> getComponentPool() {
        u32 type = typeid(T).hash_code();

        ASSERT(componentTypes_m.find(type) != componentTypes_m.end(), "Cannot use unregistered component!");

        return std::static_pointer_cast<ComponentPool<T>>(componentPools_m[type]);
    };

private:
    std::unordered_map<u32, u16> componentTypes_m{};
    std::unordered_map<u32, Shared<ComponentPool_I>> componentPools_m{};

    u16 registeredComponents_m = 0;
};

} // namespace Lila