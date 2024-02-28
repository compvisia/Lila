#include "Registry.h"

namespace Lila {

	Registry::Registry() {
		componentHandler = std::make_unique<Internal::ComponentHandler>();

		for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
			availableEntities.push(entity);
	}


	Entity Registry::createEntity() {
		assertM(entityCount < MAX_ENTITIES, "Too many entities.");

		Entity entity = availableEntities.front();
		availableEntities.pop();
		entityCount++;

		return entity;
	}

	void Registry::destoryEntity(Entity entity) {
		assertM(entity < MAX_ENTITIES, "Entity out of range.");

		componentSets[entity].reset();
		availableEntities.push(entity);
		entityCount--;
	}


	void Registry::setSet(Entity entity, ComponentSet set) {
		assertM(entity < MAX_ENTITIES, "Entity out of range.");

		componentSets[entity] = set;
	}

	ComponentSet Registry::getSet(Entity entity) {
		assertM(entity < MAX_ENTITIES, "Entity out of range.");

		return componentSets[entity];
	}

}