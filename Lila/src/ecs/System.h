#pragma once

#include "platform/types.h"

#include "Entity.h"

#include <set>

namespace Lila {

class System {
public:
    std::set<u64> entities;
};

} // namespace Lila
