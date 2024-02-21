#pragma once

#include <bitset>

#include "Entity.h"

namespace Lila {

	static int s_componentCounter = 0;
	template <class T>
	int getComponentId() {
		static int s_componentId = s_componentCounter++;
		return s_componentId;
	}

	const unsigned int MAX_COMPONENTS = 4;
	typedef std::bitset<MAX_COMPONENTS> Mask;
	
	class ComponentData {
	public:
		// The char pointer is from a previous 'reinterpret_cast<char*>(component)' done by the registry.
		ComponentData(Entity entity, int compId, char* data) {
			this->entity = entity;
			id = compId;
			bytes = data;
		}

		Entity getEntity() { return entity; }
		int getId() { return id; }
		char* getData() { return bytes; }
		
	private:
		Entity entity;
		int id;
		char* bytes = { nullptr };
	};


}
