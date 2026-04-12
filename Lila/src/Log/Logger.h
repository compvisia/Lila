#pragma once

#include <string>
#include <format>
#include <print>
#include <type_traits>

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

        template<typename Format, typename... Args>
        void log(const LogLevel& logLevel, std::string_view profile, Format&& fmt, Args&&... args) {
            if constexpr (sizeof...(args) > 0 && std::is_convertible_v<Format, std::string_view>)
                writeLog(logLevel, profile, std::vformat(fmt, std::make_format_args(args...)));
            else
                writeLog(logLevel, profile, std::format("{}", std::forward<Format>(fmt)));
        }

    private:
        Logger() = default;

        void writeLog(const LogLevel& logLevel, std::string_view profile, std::string_view contents) {
            std::string printable = std::format("{} {} {}\033[0m",
                prefixes[static_cast<int>(logLevel)],
                profile,
                contents
            );

            std::println("{}", printable);
        }
    };

} // namespace Lila
