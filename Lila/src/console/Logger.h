#pragma once

#include "platform/Types.h"

#include "console/ConsoleTypes.h"

namespace Lila {

class Logger {

public:
    Logger() {}
    ~Logger() {}

    void log(const LogLevel& logLevel, const str fmt, ...);
};

#define LOG_FATAL(logger, fmt, ...) logger.log(Lila::LL_FATAL, fmt, ##__VA_ARGS__);
#define LOG_ERROR(logger, fmt, ...) logger.log(Lila::LL_ERROR, fmt, ##__VA_ARGS__);
#define LOG_WARN(logger, fmt, ...) logger.log(Lila::LL_WARN, fmt, ##__VA_ARGS__);

#define LOG_INFO(logger, fmt, ...) logger.log(Lila::LL_INFO, fmt, ##__VA_ARGS__);
#define LOG_DEBUG(logger, fmt, ...) logger.log(Lila::LL_DEBUG, fmt, ##__VA_ARGS__);
#define LOG_TRACE(logger, fmt, ...) logger.log(Lila::LL_TRACE, fmt, ##__VA_ARGS__);

#define LOG_FUNC(logger) logger.log(Lila::LL_FUNC, str("%s -> %s:%d"), INFO_FUNC, __FILE__, __LINE__);

} // namespace Lila
