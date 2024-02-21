#pragma once

#include "Component.h"

#include <vector>

namespace Lila {

	class Registry {
	public:
		Registry();
		~Registry();

		Entity create();
		void destroy(Entity entity);

		std::vector<Entity> getAll();

	private:
		std::vector<ComponentData*> components;
		Entity* entities{ nullptr };

	// Methods using template<>
	public:

		template<typename T>
		T* assign(Entity entity) {
			int compId = getComponentId<T>();
			
			components.push_back(
				new ComponentData(entity, compId, reinterpret_cast<char*>(new T))
			);

			return getComponent<T>(entity);
		}

		template<typename T>
		void remove(Entity entity) {
			int compId = getComponentId<T>();

			for (int i = 0; i < components.size(); i++) {
				if (components[i]->getEntity() != entity)
					continue;
				if (components[i]->getId() != compId)
					continue;
				
				components.erase(components.begin() + i);
			}
		}

		template<typename T>
		T* getComponent(Entity entity) {
			int compId = getComponentId<T>();

			for(int i = 0; i < components.size(); i++) {
				if(components[i]->getEntity() != entity)
					continue;
				if(components[i]->getId() != compId)
					continue;

				return reinterpret_cast<T*>(components[i]->getData());
			}
			
			return nullptr;
		}

		template<typename T>
		bool hasComponent(Entity entity) {
			int compId = getComponentId<T>();

			for (int i = 0; i < components.size(); i++) {
				if (components[i]->getEntity() != entity)
					continue;
				if (components[i]->getId() != compId)
					continue;
				
				return true;
			}
			
			return false;
		}

		template<typename T>
		std::vector<Entity> getEntitiesWith() {
			std::vector<Entity> ents;

			for (int i = 0; i < MAX_ENTITIES; i++) {
				if(!hasComponent<T>(i))
					continue;

				ents.push_back(i);
			}

			return ents;
		}
	};

}