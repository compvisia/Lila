#pragma once

#include "Entity.h"

#include "Platform/Defines.h"

#include "Lila/core/Logger.h"

#include <vector>
#include <unordered_map>

namespace Lila {

	class IComponentPool {
	public:
		virtual ~IComponentPool() = default;
		virtual void entityDestroyed(u64 entity) = 0;
	};

	template<typename T>
	class ComponentPool : public IComponentPool {
	public:
		void addComponent(u64 entity, Shared<T> component) {
			lila_assert_msg(entityToIndex_m.find(entity) == entityToIndex_m.end(), "Trying to add component more than once to an entity.");

			u64 index = size_m;
			entityToIndex_m[entity] = index;
			indexToEntity_m[index] = entity;

			componentMap_m[index] = component;
			size_m++;
		}

		void removeComponent(u64 entity) {
			lila_assert_msg(entityToIndex_m.find(entity) != entityToIndex_m.end(), "Trying to remove non-existent component.");

			u64 indexRemovedU64 = entityToIndex_m[entity];
			u64 indexLast = size_m - 1;
			componentMap_m[indexRemovedU64] = componentMap_m[indexLast];

			u64 entityLast = indexToEntity_m[indexLast];
			entityToIndex_m[indexLast] = indexRemovedU64;
			indexToEntity_m[indexRemovedU64] = entityLast;

			entityToIndex_m.erase(entity);
			indexToEntity_m.erase(entityLast);

			size_m--;
		}

		Shared<T> getComponent(u64 entity) {
			lila_assert_msg(entityToIndex_m.find(entity) != entityToIndex_m.end(), "Trying to retrieve a non-existent component.");

			return componentMap_m[entityToIndex_m[entity]];
		}


		void entityDestroyed(u64 entity) override {
			if (entityToIndex_m.find(entity) == entityToIndex_m.end())
				return;

			removeComponent(entity);
		}

	private:
		std::unordered_map<i64,Shared<T>> componentMap_m;

		std::unordered_map<u64, i64> entityToIndex_m;
		std::unordered_map<i64, u64> indexToEntity_m;

		u64 size_m;
	};

}