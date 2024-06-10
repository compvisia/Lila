#pragma once

#include "Platform/Defines.h"

#include <bitset>

namespace Lila {

	const u16 MAX_COMPONENTS = 512;

	using ComponentMask = std::bitset<MAX_COMPONENTS>;

}