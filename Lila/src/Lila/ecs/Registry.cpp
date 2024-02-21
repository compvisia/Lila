#include "Registry.h"

namespace Lila {

	Registry::Registry() {
		entities = new Entity[MAX_ENTITIES];

		for(int i = 0; i < MAX_ENTITIES; i++) {
			entities[i] = -1;
		}
	}

	Registry::~Registry() {
		for(auto component : components)
			delete component;
		components.clear();

		delete [] entities;
	}

	Entity Registry::create() {
		for(int i = 0; i < MAX_ENTITIES; i++) {
			if(entities[i] != -1)
				continue;
			return i;
		}
		return -1;
	}

	void Registry::destroy(Entity entity) {
		for(int i = 0; i < components.size(); i++) {
			if(components[i]->getEntity() != entity)
				continue;
			components.erase(components.begin() + i);
		}

		entities[entity] = -1;
	}

	std::vector<Entity> Registry::getAll() {
		std::vector<Entity> ents;

		for(int i = 0; i < MAX_ENTITIES; i++) {
			ents.push_back(i);
		}

		return ents;
	}

}