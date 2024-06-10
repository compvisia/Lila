#include "Registry.h"

#include "Lila/Core/Logger.h"

#include "Lila/Math/Math.h"

namespace Lila {

	Registry::Registry() {
		componentHandler_m = makeUnique<ComponentHandler>();
		systemHandler_m = makeUnique<SystemHandler>();

		entityCount_m = 0;
		maxEntities_m = ceil(MAX_ENTITIES/65536);

		componentMasks_m.resize(maxEntities_m);

		for (u64 entity = 0; entity < maxEntities_m; entity++)
			availableEntities_m.push(entity);
	}


	u64 Registry::create() {
		lila_assert_msg(entityCount_m < MAX_ENTITIES, "Too many entities.");

		if (entityCount_m >= maxEntities_m) {
			maxEntities_m++;
			availableEntities_m.push(maxEntities_m);
		}

		u32 entity = availableEntities_m.front();
		availableEntities_m.pop();
		entityCount_m++;

		return entity;
	}

	void Registry::destroy(u64 entity) {
		lila_assert_msg(entity < maxEntities_m, "Entity out of range.");

		componentMasks_m[entity].reset();
		availableEntities_m.push(entity);
		entityCount_m--;

		componentHandler_m->entityDestroyed(entity);
		systemHandler_m->entityDestroyed(entity);
	}


	void Registry::setMask(u64 entity, ComponentMask set) {
		lila_assert_msg(entity < maxEntities_m, "Entity out of range.");

		componentMasks_m[entity] = set;
	}

	ComponentMask Registry::getMask(u64 entity) {
		lila_assert_msg(entity < maxEntities_m, "Entity out of range.");

		return componentMasks_m[entity];
	}


	u64 Registry::getCount() {
		return entityCount_m;
	}
}