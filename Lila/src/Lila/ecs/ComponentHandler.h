#pragma once

#include "ComponentPool.h"

#include <array>

namespace Lila {
	namespace Internal {

		class ComponentHandler {
		public:
			template<typename T>
			void registerComponent() {
				const char* type = typeid(T).name();

				assertM(componentTypes.find(type) == componentTypes.end(), "Trying to register a component more than once.");

				componentTypes.insert({ type, nextType });
				componentPools.insert({ type, std::make_shared<ComponentPool<T>>() });
				++nextType;
			};


			template<typename T>
			ComponentType getComponentType() {
				const char* type = typeid(T).name();

				assertM(componentTypes.find(type) != componentTypes.end(), "Trying to use unregisterd component.");

				return componentTypes[type];
			};


			template<typename T>
			void assign(Entity entity, T component) {
				getComponentPool<T>()->addData(entity, component);
			};

			template<typename T>
			void remove(Entity entity) {
				getComponentPool<T>()->removeData(entity);
			};

			template<typename T>
			T& getComponent(Entity entity) {
				return getComponentPool<T>()->getData(entity);
			};


			template<typename T>
			void enityDestroyed(Entity entity) {
				for (auto const& pair : componentPools) {
					auto const& component = pair.second;
					component->entityDestroyed(entity);
				}
			};

		private:
			std::unordered_map<const char*, ComponentType> componentTypes{};
			std::unordered_map<const char*, std::shared_ptr<IComponentPool>> componentPools{};

			ComponentType nextType{};

		private:
			template<typename T>
			std::shared_ptr<ComponentPool<T>> getComponentPool() {
				const char* type = typeid(T).name();

				assertM(componentTypes.find(type) != componentTypes.end(), "Trying to use unregisterd component.");

				return std::static_pointer_cast<ComponentPool<T>>(componentPools[type]);
			};
		};
	}
}