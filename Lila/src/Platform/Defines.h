#pragma once

#include <cstdint>

/**
 * Unsigned 8 bit integer
*/
using u8  = uint8_t;
/**
 * Unsigned 16 bit integer
*/
using u16 = uint16_t;
/**
 * Unsigned 32 bit integer
*/
using u32 = uint32_t;
/**
 * Unsigned 64 bit integer
*/
using u64 = uint64_t;

/**
 * Signed 8 bit integer
*/
using i8  = int8_t;
/**
 * Signed 16 bit integer
*/
using i16 = int16_t;
/**
 * Signed 32 bit integer
*/
using i32 = int32_t;
/**
 * Signed 64 bit integer
*/
using i64 = int64_t;

/**
 * 8 bit boolean
*/
using b8  = uint8_t;
/**
 * 16 bit boolean
*/
using b16 = uint16_t;
/**
 * 32 bit boolean
*/
using b32 = uint32_t;
/**
 * 64 bit boolean
*/
using b64 = uint64_t;

/**
 * 32 bit float
*/
using f32 = float;
/**
 * 64 bit float
*/
using f64 = double;

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
#error "Unknown Apple platform"
#endif
#elif defined(msys2)
#define LILA_PLATFORM_MSYS 1
#else
#error "Unknown platform"
#endif