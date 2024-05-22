#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
// Windows
#ifndef _WIN64
#error "64-bit is required"
#endif
#define LILA_PLATFORM_WINDOWS 1
#elif defined(__ANDROID__)
// Android
#define LILA_PLATFORM_ANDROID 1
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux
#define LILA_PLATFORM_LINUX 1
#elif defined(__UNIX__)
// Unix
#define LILA_PLATFORM_UNIX 1
#elif __APPLE__
// Apple
#define LILA_PLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define LILA_PLATFORM_IOS 1
#define LILA_PLATFORM_IOS_SIM 1
#elif TARGET_OS_PHONE
// iOS Device
#define LILA_PLATFORM_IOS 1
#elif TARGET_OS_MAC
// Mac OS
#define LILA_PLATFORM_MACOS 1
#else
#error "Unkown Apple platform"
#endif
#elif defined(msys2)
#define LILA_PLATFORM_MSYS 1
#else
#error "Unkown platform"
#endif