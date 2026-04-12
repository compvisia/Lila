#pragma once

#include <vector>

#include "Log/Macros.h"

#include "Entity.h"

namespace Lila::ECS {

    template<typename Component>
    class SparseSet {
    public:
        void insert(Entity entity, const Component& component) {
            if (entity >= sparse_m.size())
                sparse_m.resize(entity + 1, invalidIndex_m);

            if (sparse_m[entity] != invalidIndex_m) {
                dense_m[sparse_m[entity]] = component;
                return;
            }

            sparse_m[entity] = dense_m.size();
            dense_m.push_back(component);
            entities_m.push_back(entity);
        }

        void remove(Entity entity) {
            LILA_ASSERT(entity < sparse_m.size() && sparse_m[entity] != invalidIndex_m, "Entity does not exist in SparseSet");

            size_t index = sparse_m[entity];
            size_t lastIndex = dense_m.size() - 1;

            dense_m[index] = dense_m[lastIndex];
            Entity lastEntity = entities_m[lastIndex];
            entities_m[index] = lastEntity;
            sparse_m[lastEntity] = index;

            dense_m.pop_back();
            entities_m.pop_back();
            sparse_m[entity] = invalidIndex_m;
        }

        Component& get(Entity entity) {
            LILA_ASSERT(entity < sparse_m.size() && sparse_m[entity] != invalidIndex_m, "Entity does not exist in SparseSet");

            return dense_m[sparse_m[entity]];
        }

        bool contains(Entity entity) const {
            return entity < sparse_m.size() && sparse_m[entity] != invalidIndex_m;
        }

        size_t size() const {
            return dense_m.size();
        }

        auto begin() {
            return dense_m.begin();
        }

        auto end() {
            return dense_m.end();
        }

        auto entitiesBegin() {
            return entities_m.begin();
        }

        auto entitiesEnd() {
            return entities_m.end();
        }

    private:
        inline const static size_t invalidIndex_m = SIZE_MAX;
        std::vector<Component> dense_m;
        std::vector<Entity> entities_m;
        std::vector<size_t> sparse_m;
    };

} // namespace Lila::ECS
