#include "Logger.h"

#include <cstdio>
#include <cstdarg>

namespace Lila {

    constexpr const c8* prefixes[] = {
        "\x1b[41m[FATAL]",
        "\x1b[91m[ERROR]",
        "\x1b[93m[WARN] ",
        "\x1b[94m[INFO] ",
        "\x1b[96m[DEBUG]",
        "\x1b[36m[TRACE]",
        "\x1b[1;41m[ASSERT]",
        "\x1b[1;46m[DEBUG_ASSERT]",
    };

    void Logger::log(const LogLevel& logLevel, const std::string& profile, const c8* fmt, ...) {
        printf("%s (%s) : ", prefixes[static_cast<int>(logLevel)], profile.c_str());

        va_list arguments;
        va_start(arguments, fmt);
        vprintf(fmt, arguments);
        va_end(arguments);

        printf("\033[0m\n");
    }
}
