#pragma once

#include "System.h"
#include "Component.h"
#include "Lila/core/Core.h"
#include "Lila/core/Logger.h"

#include <unordered_map>

namespace Lila {

	namespace Internal {

		class SystemHandler {
		public:
			template<typename T>
			Ref<T> registerSystem() {
				const char* type = typeid(T).name();

				assertM(systems.find(type) == systems.end(), "Trying to register a system more than once.");

				auto system = std::make_shared<T>();
				systems.insert({ type, system });
				return system;
			}

			template<typename T>
			void setComponentSet(ComponentSet set) {
				const char* type = typeid(T).name();

				assertM(systems.find(type) != systems.end(), "Trying to use unregisterd component.");

				componentSets.insert({ type, set });
			}

			void entityDestroyed(Entity entity) {
				for (auto const& pair : systems) {
					auto const& system = pair.second;

					system->entities.erase(entity);
				}
			}

			void componentSetChanged(Entity entity, ComponentSet set) {
				for (auto const& pair : systems)
				{
					auto const& type = pair.first;
					auto const& system = pair.second;
					auto const& systemSet = componentSets[type];

					if ((set & systemSet) == systemSet)
						system->entities.insert(entity);
					else
						system->entities.erase(entity);
				}
			}

		private:
			std::unordered_map<const char*, ComponentSet> componentSets{};
			std::unordered_map<const char*, Ref<System>> systems{};
		};
	}
}