#pragma once

#include "platform/types.h"

#include "console/ConsoleTypes.h"

namespace Lila {

class Logger {
public:
    virtual ~Logger() {}

    static void log(const LogLevel& logLevel, const str fmt, ...);
};

#define LOG_FATAL(fmt, ...) Lila::Logger::log(Lila::LL_FATAL, fmt, ##__VA_ARGS__);
#define LOG_ERROR(fmt, ...) Lila::Logger::log(Lila::LL_ERROR, fmt, ##__VA_ARGS__);
#define LOG_WARN(fmt, ...) Lila::Logger::log(Lila::LL_WARN, fmt, ##__VA_ARGS__);

#define LOG_INFO(fmt, ...) Lila::Logger::log(Lila::LL_INFO, fmt, ##__VA_ARGS__);
#define LOG_DEBUG(fmt, ...) Lila::Logger::log(Lila::LL_DEBUG, fmt, ##__VA_ARGS__);
#define LOG_TRACE(fmt, ...) Lila::Logger::log(Lila::LL_TRACE, fmt, ##__VA_ARGS__);

#define LOG_FUNC() Lila::Logger::log(Lila::LL_FUNC, str("%s -> %s:%d"), INFO_FUNC, __FILE__, __LINE__);

} // namespace Lila
