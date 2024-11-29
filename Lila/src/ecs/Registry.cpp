#include "Registry.h"

#include "console/Logger.h"

namespace Lila {

Registry::Registry() {
    componentHandler_m = unique<ComponentHandler>();
    systemHandler_m = unique<SystemHandler>();

    entityCount_m = 512;
    reserveCount_m = 512;

    componentMasks_m.resize(reserveCount_m);

    for(u64 entity = 0; entity < reserveCount_m; entity++)
        entityReserve_m.push(entity);
}

// <?> How does the Registry handle component masks?
u64 Registry::create() {
    u64 threshold = 10;
    if(entityCount_m - threshold >= reserveCount_m) {
        u64 oldReserveCount = reserveCount_m;
        reserveCount_m += 512;
 
        ASSERT(oldReserveCount >= reserveCount_m, "Too many entities!");

        for(u64 entity = oldReserveCount; entity < reserveCount_m; entity++)
            entityReserve_m.push(entity);
        
        componentMasks_m.resize(reserveCount_m);
    }

    u64 entity = entityReserve_m.front();
    entityReserve_m.pop();
    entityCount_m++;
    
    return entity;
}

void Registry::destroy(u64 entity) {
    componentMasks_m[entity].reset();
    entityReserve_m.push(entity);
    entityCount_m--;
}

u64 Registry::getEntityCount() {
    return entityCount_m;
}

void Registry::setMask(u64 entity, ComponentMask mask) {
    componentMasks_m[entity] = mask;
}

ComponentMask Registry::getMask(u64 entity) {
    return componentMasks_m[entity];
}

} // namespace Lila
