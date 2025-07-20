#pragma once

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
}
