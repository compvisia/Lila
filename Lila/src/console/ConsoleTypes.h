#pragma once

#include "platform/platform.h"

namespace Lila {

enum LogLevel {
    LL_FATAL,
    LL_ERROR,
    LL_WARN,
    LL_INFO,
    LL_DEBUG,
    LL_TRACE,
    LL_FUNC
};

#if LILA_PLATFORM_WINDOWS
#define INFO_FUNC __FUNCSIG__
#elif LILA_PLATFORM_LINUX
#define INFO_FUNC __PRETTY_FUNCTION__
#elif LILA_PLATFORM_APPLE
#define INFO_FUNC __PRETTY_FUNCTION__
#else
#define INFO_FUNC __func__
#endif

}