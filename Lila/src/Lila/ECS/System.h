#pragma once

#include "Entity.h"

#include "Platform/Defines.h"

#include <set>

namespace Lila {

	class System {
	public:
		std::set<u64> entities;
	};

}