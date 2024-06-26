#pragma once

#include "System.h"
#include "Component.h"

#include "Lila/Core/Logger.h"

#include "Lila/Utils/Memory.h"

#include "Platform/Defines.h"

#include <typeinfo>
#include <unordered_map>

namespace Lila {
	class SystemHandler {
	public:
		template<typename T>
		Shared<T> registerSystem() {
			u32 type = typeid(T).hash_code();

			lila_assert_msg(systems_m.find(type) == systems_m.end(), "Trying to register a system more than once.");

			Shared<T> system = makeShared<T>();
			systems_m.insert({ type, system });
			return system;
		}

		template<typename T>
		void setComponentMask(ComponentMask set) {
			u32 type = typeid(T).hash_code();

			lila_assert_msg(systems_m.find(type) != systems_m.end(), "Trying to use unregistered component.");

			componentMasks_m.insert({ type, set });
		}

		void entityDestroyed(u32 entity) {
			for (const std::pair<u32, Shared<System>>& pair : systems_m) {
				const Shared<System> system = pair.second;

				system->entities.erase(entity);
			}
		}

		void componentMaskChanged(u32 entity, ComponentMask set) {
			for (const std::pair<u32, Shared<System>>& p : systems_m)
			{
				const u32 type = p.first;
				const Shared<System> system = p.second;
				const ComponentMask systemSet = componentMasks_m[type];

				if ((set & systemSet) == systemSet)
					system->entities.insert(entity);
				else
					system->entities.erase(entity);
			}
		}

	private:
		std::unordered_map<u32, ComponentMask> componentMasks_m;
		std::unordered_map<u32, Shared<System>> systems_m;
	};
}