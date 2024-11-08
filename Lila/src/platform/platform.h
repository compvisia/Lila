#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#ifndef _WIN64
#error "64-bit is required"
#endif
#define LILA_PLATFORM_WINDOWS 1
#elif defined(__linux__) || defined(__gnu_linux__)
#define LILA_PLATFORM_LINUX 1
#elif __APPLE__
#define LILA_PLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define LILA_PLATFORM_IOS 1
#define LILA_PLATFORM_IOS_SIM 1
#elif TARGET_OS_PHONE
#define LILA_PLATFORM_IOS 1
#elif TARGET_OS_MAC
#define LILA_PLATFORM_MACOS 1
#else
#error "Unknown Apple platform"
#endif
#error "Unknown platform"
#endif