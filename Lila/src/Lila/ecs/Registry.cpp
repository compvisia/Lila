#include "Registry.h"

namespace Lila {

	Registry::Registry() {
		componentHandler = std::make_unique<Internal::ComponentHandler>();
		systemHandler    = std::make_unique<Internal::SystemHandler>();

		for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
			availableEntities.push(entity);
	}


	Entity Registry::createEntity() {
		lila_assert_msg(entityCount < MAX_ENTITIES, "Too many entities.");

		Entity entity = availableEntities.front();
		availableEntities.pop();
		entityCount++;

		return entity;
	}

	void Registry::destroyEntity(Entity entity) {
		lila_assert_msg(entity < MAX_ENTITIES, "Entity out of range.");

		componentSets[entity].reset();
		availableEntities.push(entity);
		entityCount--;

		componentHandler->entityDestroyed(entity);
		systemHandler->entityDestroyed(entity);
	}


	void Registry::setSet(Entity entity, ComponentSet set) {
		lila_assert_msg(entity < MAX_ENTITIES, "Entity out of range.");

		componentSets[entity] = set;
	}

	ComponentSet Registry::getSet(Entity entity) {
		lila_assert_msg(entity < MAX_ENTITIES, "Entity out of range.");

		return componentSets[entity];
	}
	

	uint32_t Registry::getCount() {
		return entityCount;
	}
}