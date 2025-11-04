#pragma once

#include "Types.h"

namespace Lila {

    class UUID {
    public:
        UUID();
        ~UUID() = default;

        operator u64() const {
            return uuid_m;
        }

        UUID(const UUID& other) = delete;
        UUID& operator=(const UUID& other) = delete;

        UUID(UUID&& other) = default;
        UUID& operator=(UUID&& other) = default;

        bool operator==(const UUID& other) const {
            return uuid_m == other.uuid_m;
        }

        bool operator!=(const UUID& other) const {
            return !(*this == other);
        }

    private:
        u64 uuid_m;
    };

} // namespace Lila
