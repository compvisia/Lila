#pragma once

#include <bitset>
#include <cstdint>

namespace Lila::ECS {

    constexpr size_t MAX_COMPONENTS = 64;
    using ComponentSignature = std::bitset<MAX_COMPONENTS>;

} // namespace Lila::ECS
