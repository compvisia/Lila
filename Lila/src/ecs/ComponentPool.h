#pragma once

#include "platform/types.h"

#include "console/Logger.h"

#include <unordered_map>

// TODO: Improvements (archetypes)
namespace Lila {

class ComponentPool_I {
public:
    virtual ~ComponentPool_I() = default;
    virtual void entityDestroyed(u64 entity) = 0;
};

template<typename T>
class ComponentPool : public ComponentPool_I {
public:
    void addComponent(u64 entity, Shared<T> component) {
            ASSERT(entityToIndex_m.find(entity) == entityToIndex_m.end(), "Cannot add the same type of component on an entity!");

        u64 index = poolSize_m;
        entityToIndex_m[entity] = index;
        indexToEntity_m[index] = entity;

        componentMap_m[index] = component;
        poolSize_m++;
    }

    void removeComponent(u64 entity) {
         ASSERT(entityToIndex_m.find(entity) == entityToIndex_m.end(), "Cannot remove non-existent component!");

        u64 indexRemovedU64 = entityToIndex_m[entity];
        u64 indexLast = poolSize_m - 1;
        componentMap_m[indexRemovedU64] = componentMap_m[indexLast];

        u64 entityLast = indexToEntity_m[indexLast];
        entityToIndex_m[indexLast] = indexRemovedU64;
        indexToEntity_m[indexRemovedU64] = entityLast;

        entityToIndex_m.erase(entity);
        indexToEntity_m.erase(entityLast);

        poolSize_m--;
    }

    void entityDestroyed(u64 entity) override {
        if (entityToIndex_m.find(entity) == entityToIndex_m.end())
            return;

        removeComponent(entity);
    }

    Shared<T> getComponent(u64 entity) {
        ASSERT(entityToIndex_m.find(entity) != entityToIndex_m.end(), "Cannot get non-existent component!");

        return componentMap_m[entityToIndex_m[entity]];
    }

    u64 getPoolSize() {
        return poolSize_m;
    }

private:
    std::unordered_map<i64,Shared<T>> componentMap_m;

    std::unordered_map<u64, i64> entityToIndex_m;
    std::unordered_map<i64, u64> indexToEntity_m;

    u64 poolSize_m;
};

} // namespace Lila
