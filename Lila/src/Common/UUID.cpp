#include "UUID.h"
#include "Types.h"

#include <random>

namespace Lila {

    static std::random_device randomDevice_s;
    static std::mt19937_64 mt19937_s(randomDevice_s());
    static std::uniform_int_distribution<u64> uniformIntDistribution_s;

    UUID::UUID() {
        uuid_m = uniformIntDistribution_s(mt19937_s);
    }

} // namespace Lila
