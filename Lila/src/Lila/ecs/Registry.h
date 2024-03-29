#pragma once

#include "SystemHandler.h"
#include "ComponentHandler.h"

#include <cstddef>
#include <utility>
#include <memory>
#include <queue>

namespace Lila {

	class Registry {
	public:
		Registry();
		
		Entity createEntity();
		void destroyEntity(Entity entity);
		
		void setSet(Entity entity, ComponentSet set);
		ComponentSet getSet(Entity entity);

		uint32_t getCount();

	private:
		std::queue<Entity> availableEntities{};
		std::array<ComponentSet, MAX_ENTITIES> componentSets{};
		uint32_t entityCount{};

		std::unique_ptr<Internal::ComponentHandler> componentHandler;
		std::unique_ptr<Internal::SystemHandler>    systemHandler;

	public: // Methods of the Handlers

		// ComponentHandler
		template<typename T>
		void registerComponent() { componentHandler->registerComponent<T>(); };

		template<typename T>
		ComponentType getComponentType() { return componentHandler->getComponentType<T>(); };

		template<typename T>
		void assign(Entity entity, T component) {
			
			componentHandler->assign<T>(entity, component);
			
			auto set = getSet(entity);
			set.set(getComponentType<T>());
			setSet(entity, set);

			systemHandler->componentSetChanged(entity, set);
		};

		template<typename T>
		void remove(Entity entity) { componentHandler->remove<T>(entity); };

		template<typename T>
		T& getComponent(Entity entity) { return componentHandler->getComponent<T>(entity); };

		// SystemHandler
		template<typename T>
		Ref<T> registerSystem() { return systemHandler->registerSystem<T>(); };

		template<typename T>
		void setComponentSet(ComponentSet set) { systemHandler->setComponentSet<T>(set); };
	};
}