#pragma once

#include "Entity.h"
#include "ComponentPool.h"

#include <vector>
#include <bitset>

namespace Lila {

    class World {
    public:
        World();
        ~World();

        Entity createNew();
        EntityInfo getInfo(Entity entity);

        
        template<typename T>
        T* assign(Entity entity) {
            int componentId = GetId<T>();

            if(components.size() <= componentId)
                components.resize(componentId + 1);
            
            if(components[componentId] == nullptr)
                components[componentId] = new ComponentPool(sizeof(T));

            T* component = new (components[componentId]->get(entity)) T();
            
            entities[entity].mask.set(componentId);
            return component;
        }

        template<typename T>
            T* getComponent(Entity entity) {
            int componentId = GetId<T>();

            if(!entities[entity].mask.test(componentId))
                return nullptr;

            T* component = static_cast<T*>(components[componentId]->get(entity));
            return component;
        }

    private:
        std::vector<ComponentPool*> components;
        std::vector<EntityInfo> entities;
    };
    
}