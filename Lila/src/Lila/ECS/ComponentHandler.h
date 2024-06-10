#pragma once

#include "ComponentPool.h"

#include "Lila/Utils/Memory.h"

#include "Platform/Defines.h"

#include <typeinfo>

namespace Lila {
	class ComponentHandler {
	public:
		template<typename T>
		void registerComponent() {
			u32 type = typeid(T).hash_code();

			lila_assert_msg(componentTypes_m.find(type) == componentTypes_m.end(), "Trying to register a component more than once.");

			componentTypes_m.insert({ type, nextType_m });
			componentPools_m.insert({ type, makeShared<ComponentPool<T>>() });
			nextType_m++;
		};


		template<typename T>
		u16 getComponentType() {
			u32 type = typeid(T).hash_code();

			lila_assert_msg(componentTypes_m.find(type) != componentTypes_m.end(), "Trying to use unregisterd component.");

			return componentTypes_m[type];
		};


		template<typename T>
		void addComponent(u64 entity, Shared<T> component) {
			getComponentPool<T>()->addComponent(entity, component);
		};

		template<typename T>
		void removeComponent(u64 entity) {
			getComponentPool<T>()->removeComponent(entity);
		};

		template<typename T>
		Shared<T> getComponent(u64 entity) {
			return getComponentPool<T>()->getComponent(entity);
		};


		void entityDestroyed(u64 entity) {
			for (auto const& pair : componentPools_m) {
				auto const& component = pair.second;
				component->entityDestroyed(entity);
			}
		};

	private:
		template<typename T>
		Shared<ComponentPool<T>> getComponentPool() {
			u32 type = typeid(T).hash_code();

			lila_assert_msg(componentTypes_m.find(type) != componentTypes_m.end(), "Trying to use unregisterd component.");

			return std::static_pointer_cast<ComponentPool<T>>(componentPools_m[type]);
		};

	private:
		std::unordered_map<u32, u16> componentTypes_m{};
		std::unordered_map<u32, Shared<IComponentPool>> componentPools_m{};

		u16 nextType_m;
	};
}