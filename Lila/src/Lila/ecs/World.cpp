#include "World.h"

namespace Lila {

    World::World() {

    }

    World::~World() {
        
    }


    Entity World::createNew() {
        entities.push_back({entities.size(), Mask()});

        assign<Transform>(entities.back().entity);
        assign<Tag>(entities.back().entity);

        return entities.back().entity;
    }

    void World::deleteEntity(Entity entity) {
        
    }

    EntityInfo World::getInfo(Entity entity) {
        return entities[entity];
    }
    
}