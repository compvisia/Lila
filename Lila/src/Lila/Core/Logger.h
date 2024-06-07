#pragma once

#include "Platform/Defines.h"

#include <iostream>
#include <cstring>
#include <cstdarg>
#include <string>

namespace Lila {
	
	typedef enum LogLevel {
		LL_FATAL,
		LL_ASSERT,
		LL_ERROR,
		LL_WARN,
		LL_DEBUG,
		LL_INFO,
		LL_TRACE,
	};

	static void _log(LogLevel logLevel, const std::string fmt, ...) {

		static std::string prefixes[] = {
			"[FATAL] :",
			"[ASSERT]:",
			"[ERROR] :",
			"[WARN]  :",
			"[DEBUG] :",
			"[INFO]  :",
			"[TRACE] :"
		};

		va_list arg_ptr;

		static std::string color[] = {
			"\x1b[31m",        // Dark Red (LL_FATAL)
			"\x1b[91;1m",      // Bold Red (LL_ASSERT)
			"\x1b[91m",        // Red      (LL_ERROR)
			"\x1b[93m",        // Yellow   (LL_WARN)
			"\x1b[96m",        // Cyan     (LL_DEBUG)
			"\x1b[94m",        // Blue     (LL_INFO)
			"\x1b[35m"         // Purple   (LL_TRACE)
		};

		static std::string exitColor = "\033[0m";
	
		printf("%s%s ", color[logLevel].c_str(), prefixes[logLevel].c_str());

		#ifdef LILA_PLATFORM_WINDOWS
			__crt_va_start(arg_ptr, fmt);
			vprintf(fmt.c_str(), arg_ptr);
			__crt_va_end(arg_ptr);
		#elif LILA_PLATFORM_LINUX
			__builtin_va_start(arg_ptr, fmt);
			vprintf(fmt.c_str(), arg_ptr);
			__builtin_va_end(arg_ptr);
		#else
			va_start(arg_ptr, fmt);
			vprintf(fmt.c_str(), arg_ptr);
			va_end(arg_ptr);
		#endif

		printf("%s", exitColor.c_str());

		printf("\n");
	}

#define lila_fatal(fmt, ...) _log(Lila::LL_FATAL, fmt, ##__VA_ARGS__);
#define lila_error(fmt, ...) _log(Lila::LL_ERROR, fmt, ##__VA_ARGS__);
#define lila_warn(fmt, ...)  _log(Lila::LL_WARN,  fmt, ##__VA_ARGS__);

#ifdef DEBUG
	#define lila_debug(fmt, ...) _log(Lila::LL_DEBUG, fmt, ##__VA_ARGS__);
	#define lila_info(fmt, ...)  _log(Lila::LL_INFO,  fmt, ##__VA_ARGS__);
	#define lila_trace(fmt, ...) _log(Lila::LL_TRACE, fmt, ##__VA_ARGS__);
#else 
	#define lila_debug(fmt, ...);
	#define lila_info(fmt, ...);
	#define lila_trace(fmt, ...);
#endif

#ifdef LILA_PLATFORM_WINDOWS
	#define lila_debug_break() __debugbreak();
#else
	#define lila_debug_break() __builtin_trap();
#endif

#define lila_assert(expr) {\
		if(expr) {\
		} else {\
			_log(Lila::LL_ASSERT,"Assertion: %s, in file %s:%d", #expr, __FILE__, __LINE__);\
			lila_debug_break();\
		}\
	}

#define lila_assert_msg(expr, fmt) {\
		if(expr) {\
		} else {\
			_log(Lila::LL_ASSERT,"Assertion: %s, message: %s, in file %s:%d", #expr, fmt, __FILE__, __LINE__);\
			lila_debug_break();\
		}\
	}
}