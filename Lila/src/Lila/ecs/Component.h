#pragma once

#include <bitset>

#include "Lila/utils/Vectors.h"

namespace Lila {

	using ComponentType = std::uint8_t;
	const ComponentType MAX_COMPONENTS = 32;

	using ComponentSet = std::bitset<MAX_COMPONENTS>;


	// Components

	struct Tag {
		char* name = "Entity";
	};

	struct Transform {
		int position = 1;
	};
}
