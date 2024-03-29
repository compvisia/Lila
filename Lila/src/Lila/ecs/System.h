#pragma once

#include "Entity.h"

#include <set>

namespace Lila {
	
	class System {
	public:
		std::set<Entity> entities;

	};

}