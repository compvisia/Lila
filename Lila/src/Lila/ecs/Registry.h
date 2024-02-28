#pragma once

#include "Entity.h"
#include "ComponentHandler.h"

#include <queue>

namespace Lila {

	class Registry {
	public:
		Registry();
		
		Entity createEntity();
		void destoryEntity(Entity entity);
		
		void setSet(Entity entity, ComponentSet set);
		ComponentSet getSet(Entity entity);

	private:
		std::queue<Entity> availableEntities{};
		std::array<ComponentSet, MAX_ENTITIES> componentSets{};
		uint32_t entityCount{};

		std::unique_ptr<Internal::ComponentHandler> componentHandler;

	public: // Methods of the Handlers

		// ComponentHandler
		template<typename T>
		void registerComponent() { componentHandler->registerComponent<T>(); };

		template<typename T>
		void getComponentType() { componentHandler->getComponentType<T>(); };

		template<typename T>
		void assign(Entity entity, T component) { componentHandler->assign<T>(entity, component); };

		template<typename T>
		void remove(Entity entity) { componentHandler->remove<T>(entity); };

		template<typename T>
		T& getComponent(Entity entity) { return componentHandler->getComponent<T>(entity); };
	};
}