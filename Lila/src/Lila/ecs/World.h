#pragma once

#include <vector>
#include <bitset>

namespace Lila {

    typedef unsigned long long Entity;
    typedef std::bitset<32> Mask;

    struct EntityInfo {
        Entity entity;
        Mask mask;
    };

    static int s_componentCounter = 0;
    template <class T>
    int GetId() {
        static int s_componentId = s_componentCounter++;
        return s_componentId;
    }

    class World {
    public:
        World();
        ~World();

        Entity createNew();

        template<typename T>
        void assign(Entity id) {
            int compId = GetId<T>();
            entities[id].mask.set(compId);
        }

        EntityInfo getInfo(Entity id);

    private:
        std::vector<EntityInfo> entities;
    };
    
}