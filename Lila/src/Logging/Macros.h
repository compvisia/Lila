#pragma once

#include "Logger.h"

namespace Lila {

    #define LILA_FATAL(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::FATAL, "Lila", fmt, ##__VA_ARGS__)
    #define LILA_ERROR(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::ERROR, "Lila", fmt, ##__VA_ARGS__);
    #define LILA_WARN(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::WARN, "Lila", fmt, ##__VA_ARGS__);
    #define LILA_INFO(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::INFO, "Lila", fmt, ##__VA_ARGS__);
    #define LILA_DEBUG(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::DEBUG, "Lila", fmt, ##__VA_ARGS__);
    #define LILA_TRACE(fmt, ...) Lila::Logger::get().log(Lila::LogLevel::TRACE, "Lila", fmt, ##__VA_ARGS__);

    // TODO: Implement break
    #define LILA_ASSERT(expr, fmt, ...) { \
            if(!(expr)) { \
                Lila::Logger::get().log(Lila::LogLevel::ASSERT, #expr, fmt, ##__VA_ARGS__); \
            } \
        }
} // namespace Lila
