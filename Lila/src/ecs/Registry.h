#pragma once

#include "platform/types.h"

#include "Entity.h"
#include "Component.h"
#include "ComponentHandler.h"
#include "SystemHandler.h"

#include <queue>
#include <vector>

namespace Lila {

class Registry {
public:
    Registry();
    virtual ~Registry() {}

    u64 create();
    void destroy(u64 entity);

    u64 getEntityCount();

    void setMask(u64 entity, ComponentMask mask);
	ComponentMask getMask(u64 entity);

public:
    template<typename T>
    Shared<T> addComponent(u64 entity) {
        Shared<T> component = shared<T>();

        componentHandler_m->addComponent<T>(entity, component);

        ComponentMask mask = getMask(entity);
        mask.set(getComponentType<T>());
        setMask(entity, mask);

        systemHandler_m->componentMaskChanged(entity, mask);

        return component;
    }

    template<typename T>
    void removeComponent(u64 entity) {
        componentHandler_m->removeComponent<T>(entity);

        ComponentMask mask = getMask(entity);
        mask.flip(getComponentType<T>());
        setMask(entity, mask);

        systemHandler_m->componentMaskChanged(entity, mask);
    }

    template<typename T>
    void registerComponent() {
        componentHandler_m->registerComponent<T>();
    }

    template<typename T>
    Shared<T> getComponent(u64 entity) {
        return componentHandler_m->getComponent<T>(entity);
    } 

    template<typename T>
    u16 getComponentType() {
        return componentHandler_m->getComponentType<T>();
    }

    template<typename T>
    void registerSystem() {
        systemHandler_m->registerSystem<T>();
    }

private:
    Unique<ComponentHandler> componentHandler_m;
    Unique<SystemHandler> systemHandler_m;

    std::queue<u64> entityReserve_m;
    std::vector<ComponentMask> componentMasks_m;

    u64 entityCount_m;
    u64 reserveCount_m;
};

} // namespace Lila