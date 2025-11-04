#pragma once

#include <string>
#include <format>
#include <print>

#include "Common/Types.h"

#include "LogLevel.h"

namespace Lila {

    class Logger {
    public:
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        static Logger& get() {
            static Logger instance;
            return instance;
        }

        template<typename... Args>
        void log(const LogLevel& logLevel, const std::string& profile, const std::string& fmt, Args&&... args) {
            std::string formattedMsg = std::vformat(fmt, std::make_format_args(args...));

            std::string printable = std::format("{} ({}) {}\033[0m",
                prefixes[static_cast<int>(logLevel)],
                profile,
                formattedMsg
            );

            // Sadly std::print doesn't allow for direct string printing
            std::println("{}", printable);
        }

    private:
        Logger() = default;
    };
} // namespace Lila
