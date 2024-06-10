#pragma once

#include "Entity.h"
#include "Component.h"
#include "SystemHandler.h"
#include "ComponentHandler.h"

#include "Lila/Utils/Memory.h"

#include "Platform/Defines.h"

#include <array>
#include <queue>

namespace Lila {

	class Registry {
	public:
		Registry();

		u64 create();
		void destroy(u64 entity);

		void setMask(u64 entity, ComponentMask mask);
		ComponentMask getMask(u64 entity);

		u64 getCount();

	public: // Template Methods
		
		template<typename T>
		Shared<T> addComponent(u64 entity) {
			Shared<T> component = makeShared<T>();

			componentHandler_m->addComponent<T>(entity, component);

			ComponentMask mask = getMask(entity);
			mask.set(getComponentType<T>());
			setMask(entity, mask);

			systemHandler_m->componentMaskChanged(entity, mask);

			return component;
		}

		template<typename T>
		void removeComponent(u64 entity) { 
			componentHandler_m->removeComponent<T>(entity);

			ComponentMask mask = getMask(entity);
			mask.flip(getComponentType<T>());
			setMask(entity, mask);

			systemHandler_m->componentMaskChanged(entity, mask);
		};

		// Component Handler
		template<typename T>
		void registerComponent() {
			componentHandler_m->registerComponent<T>();
		}
		
		template<typename T>
		Shared<T> getComponent(u64 entity) {
			return componentHandler_m->getComponent<T>(entity);
		}

		template<typename T>
		u16 getComponentType() {
			return componentHandler_m->getComponentType<T>();
		}

		// System Handler
		template<typename T>
		Shared<T> registerSystem() {
			return systemHandler_m->registerSystem<T>();
		}

		template<typename T>
		void setComponentMask(ComponentMask entity) {
			systemHandler_m->setComponentMask<T>(entity);
		}

	private:
		std::queue<u64> availableEntities_m{};
		std::vector<ComponentMask> componentMasks_m;

		u64 entityCount_m;
		u64 maxEntities_m;

		Unique<ComponentHandler> componentHandler_m;
		Unique<SystemHandler> systemHandler_m;
	};







}