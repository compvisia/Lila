#pragma once

#include "Entity.h"
#include "Component.h"

#include "Lila/core/Logger.h"

#include <unordered_map>

namespace Lila {

	class IComponentPool {
	public:
		virtual ~IComponentPool() = default;
		virtual void entityDestroyed(Entity entity) = 0;
	};

	template<typename T>
	class ComponentPool : public IComponentPool {
	public:
		void addData(Entity entity, T component) {
			lila_assert_msg(entityToIndex.find(entity) == entityToIndex.end(), "Trying to add component more than once to an entity.");

			size_t index = size;
			entityToIndex[entity] = index;
			indexToEntity[index]  = entity;
			
			componentArray[index] = component;
			size++;
		}

		void removeData(Entity entity) {
			lila_assert_msg(entityToIndex.find(entity) != entityToIndex.end(), "Trying to remove non-existent component.");

			size_t indexRemovedEntity = entityToIndex[entity];
			size_t indexLast = size - 1;
			componentArray[indexRemovedEntity] = componentArray[indexLast];

			Entity entityLast = indexToEntity[indexLast];
			entityToIndex[indexLast] = indexRemovedEntity;
			indexToEntity[indexRemovedEntity] = entityLast;

			entityToIndex.erase(entity);
			indexToEntity.erase(entityLast);

			--size;
		}

		T& getData(Entity entity) {
			//lila_assert_msg(entityToIndex.find(entity) != entityToIndex.end(), "Trying to retrieve a non-existent component.");

			return componentArray[entityToIndex[entity]];
		}


		void entityDestroyed(Entity entity) override {
			if(entityToIndex.find(entity) == entityToIndex.end())
				return;

			removeData(entity);
		}

	private:
		std::array<T, MAX_ENTITIES> componentArray;

		std::unordered_map<Entity, size_t> entityToIndex;
		std::unordered_map<size_t, Entity> indexToEntity;

		size_t size;
	};

} 