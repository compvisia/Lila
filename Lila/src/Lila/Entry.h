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
#else
#error "Unkown platform"
#endif

extern Lila::Shared<Lila::Application> createApplication();

#include "Platform/Dependencies.h"

int main(int argv, char** argc) {
// Operating System
#if LILA_PLATFORM_WINDOWS
	lila_info("Platform: Windows x64")
#elif LILA_PLATFORM_LINUX
	lila_info("Platform: Linux")
#elif LILA_PLATFORM_ANDROID
	lila_info("Platform: Android")
#elif LILA_PLATFORM_UNIX
	lila_info("Platform: Unix")
#elif LILA_PLATFORM_IOS_SIM
	lila_info("Platform: iOS Simulator")
#elif LILA_PLATFORM_IOS
	lila_info("Platform: iOS Device")
#elif LILA_PLATFORM_MACOS
	lila_info("Platform: MacOS")
#elif LILA_PLATFORM_APPLE
	lila_warn("Failed to identify Apple platform")
#else
	lila_warn("Failed to identify platform")
#endif
	
// C++ Version
#ifdef _MSVC_LANG
	lila_info("C++ version: %ld", _MSVC_LANG)
#elif defined(__cplusplus)
	lila_info("C++ version: %ld", __cplusplus)
#else
	lila_warn("Failed identify C++ version")
#endif

// Compiler Version
#ifdef _MSC_VER
	lila_info("MSVC version: %d", _MSC_VER)
#elif defined(__GNUC__)
	lila_info("GNU g++ version: %d.%d.%d", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__clang__)
	lila_info("LLVM clang version: %d.%d.%d", __clang_major__, __clang_minor__, __clang_patchlevel__)
#else
	lila_warn("Failed identify C++ compiler")
#endif

	if(!initDependencies())
		return -1;

	Lila::Shared<Lila::Application> application = createApplication();
	lila_info("Created Application: %s", application->getName().c_str());
	application->create();
	application->run();

	return 0;
}