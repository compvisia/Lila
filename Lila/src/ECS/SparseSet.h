#pragma once

#include <vector>
#include <cstdint>

#include "Logging/Macros.h"

#include "Entity.h"

namespace Lila::ECS {

    template<typename Component>
    class SparseSet {
    public:
        void insert(Entity entity, const Component& component) {
            if(entity >= sparse.size())
                sparse.resize(entity + 1, invalidIndex);

            if(sparse[entity] != invalidIndex) {
                dense[sparse[entity]] = component;
                return;
            }

            sparse[entity] = dense.size();
            dense.push_back(component);
            entities.push_back(entity);
        }

        void remove(Entity entity) {
            LILA_ASSERT(entity < sparse.size() && sparse[entity] != invalidIndex, "Entity does not exist in SparseSet");

            size_t index = sparse[entity];
            size_t lastIndex = dense.size() - 1;

            dense[index] = dense[lastIndex];
            Entity lastEntity = entities[lastIndex];
            entities[index] = lastEntity;
            sparse[lastEntity] = index;

            dense.pop_back();
            entities.pop_back();
            sparse[entity] = invalidIndex;
        }

        Component& get(Entity entity) {
            LILA_ASSERT(entity < sparse.size() && sparse[entity] != invalidIndex, "Entity does not exist in SparseSet");

            return dense[sparse[entity]];
        }

        bool contains(Entity entity) const {
            return entity < sparse.size() && sparse[entity] != invalidIndex;
        }

        size_t size() const {
            return dense.size();
        }

        auto begin() {
            return dense.begin();
        }

        auto end() {
            return dense.end();
        }

        auto entitiesBegin() {
            return entities.begin();
        }

        auto entitiesEnd() {
            return entities.end();
        }

    private:
        inline const static size_t invalidIndex = -1;
        std::vector<Component> dense;
        std::vector<Entity> entities;
        std::vector<size_t> sparse;
    };

} // namespace Lila::ECS
