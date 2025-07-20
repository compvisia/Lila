#pragma once

#include <string>

#include "Common/Types.h"

#include "LogLevel.h"

namespace Lila {

    class Logger {
    public:
        static Logger& get() {
            static Logger instance;
            return instance;
        }

        void log(const LogLevel& logLevel, const std::string& profile, const c8* fmt, ...);
    private:
        Logger() = default;
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
    };
} // namespace Lila
