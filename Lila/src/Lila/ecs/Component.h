#pragma once

#include <bitset>

#include "Lila/utils/Vectors.h"

#include <string>

namespace Lila {

	using ComponentType = std::uint8_t;
	const ComponentType MAX_COMPONENTS = 32;

	using ComponentSet = std::bitset<MAX_COMPONENTS>;


	// Components

	struct Tag {
		std::string name = "Entity 1";
	};

	struct Transform {
		Vec3 position = Vec3(0, 0, 0);
		Vec3 rotation = Vec3(0, 0, 0);
		Vec3 scale    = Vec3(1, 1, 1);
	};
}
