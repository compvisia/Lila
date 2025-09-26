#pragma once

#include <string>

#include "Common/Types.h"

namespace Lila {

    enum class LogLevel : u8 {
        FATAL,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        TRACE,
        ASSERT,
        DEBUG_ASSERT
    };

    constexpr const c8* prefixes[] = {
        "\x1b[41m[FATAL]",
        "\x1b[91m[ERROR]",
        "\x1b[93m[WARN] ",
        "\x1b[94m[INFO] ",
        "\x1b[96m[DEBUG]",
        "\x1b[36m[TRACE]",
        "\x1b[1;41m[ASSERT]",
        "\x1b[1;46m[DEBUG_ASSERT]"
    };
}
