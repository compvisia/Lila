#include "World.h"

namespace Lila {

    World::World() {

    }

    World::~World() {
        
    }


    Entity World::createNew() {
        entities.push_back({entities.size(), Mask()});
        return entities.back().entity;
    }

    EntityInfo World::getInfo(Entity entity) {
        return entities[entity];
    }
    
}