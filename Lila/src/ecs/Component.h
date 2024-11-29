#pragma once

#include "platform/types.h"

#include <bitset>

namespace Lila {

constexpr u16 MAX_COMPONENTS = 512;

using ComponentMask = std::bitset<MAX_COMPONENTS>;

} // namespace Lila
