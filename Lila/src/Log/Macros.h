#pragma once

#include "Platform/Platform.h"

#include "Logger.h"

namespace Lila {

    #define LILA_FATAL(...) Lila::Logger::get().log(Lila::LogLevel::FATAL, "(Lila)", __VA_ARGS__)
    #define LILA_ERROR(...) Lila::Logger::get().log(Lila::LogLevel::ERROR, "(Lila)", __VA_ARGS__);
    #define LILA_WARN(...) Lila::Logger::get().log(Lila::LogLevel::WARN, "(Lila)", __VA_ARGS__);
    #define LILA_INFO(...) Lila::Logger::get().log(Lila::LogLevel::INFO, "(Lila)", __VA_ARGS__);
    #define LILA_DEBUG(...) Lila::Logger::get().log(Lila::LogLevel::DEBUG, "(Lila)", __VA_ARGS__);
    #define LILA_TRACE(...) Lila::Logger::get().log(Lila::LogLevel::TRACE, "(Lila)", __VA_ARGS__);

    #ifdef LILA_PLATFORM_WINDOWS
    #define LILA_TRAP() __debugbreak();
    #else
    #define LILA_TRAP() __builtin_trap();
    #endif

    #define LILA_ASSERT(expr, ...) { \
        if (!(expr)) { \
            Lila::Logger::get().log(Lila::LogLevel::ASSERT, #expr, __VA_ARGS__); \
            Lila::Logger::get().log(Lila::LogLevel::ERROR, "Assertion at:", "{}:{} {}(...)", __FILE__, __LINE__, __func__); \
            LILA_TRAP(); \
        } \
    }

} // namespace Lila
