#pragma once

#include <iostream>
#include <cstring>

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

	
	static int lastLogLevel = LL_TRACE;

	static void _log(LogLevel logLevel, const char* message, ...) {
		if(lastLogLevel < logLevel)
			return;
		//#ifdef _WIN32
		static char* textColor[] = {
			"\x1b[31m",        // Dark Red (LL_FATAL)
			"\x1b[91;1m",      // Bold Red (LL_ASSERT)
			"\x1b[91m",        // Red      (LL_ERROR)
			"\x1b[93m",        // Yellow   (LL_WARN)
			"\x1b[96m",        // Cyan     (LL_DEBUG)
			"\x1b[94m",        // Blue     (LL_INFO)
			"\x1b[35m"         // Purple   (LL_TRACE)
		};

		char* logColor = textColor[logLevel];
		char* endColor = "\033[0m";

		static char* prefixes[] = {
			"[FATAL] : ",
			"[ASSERT]: ",
			"[ERROR] : ",
			"[WARN]  : ",
			"[DEBUG] : ",
			"[INFO]  : ",
			"[TRACE] : "
		};
		char* prefix = prefixes[logLevel];
		//#else
		//#endif

		char out[1024];
		memset(out, 0, sizeof(out));
	
	#ifdef _WIN32
		va_list arg_ptr;
		__crt_va_start(arg_ptr, message);
		vsprintf(out, message, arg_ptr);
		__crt_va_end(arg_ptr);
	#else
		va_list arg_ptr;
		__builtin_va_start(arg_ptr, message);
		vsprintf(out, message, arg_ptr);
		__builtin_va_end(arg_ptr);
	#endif
		printf("%s%s", logColor, prefix);
		printf(out);
		printf("%s\n", endColor);
	}

#define fatal(message, ...) _log(Lila::LL_FATAL, message, ##__VA_ARGS__);
#define error(message, ...) _log(Lila::LL_ERROR, message, ##__VA_ARGS__);
#define warn(message, ...)  _log(Lila::LL_WARN,  message, ##__VA_ARGS__);
#define debug(message, ...) _log(Lila::LL_DEBUG, message, ##__VA_ARGS__);
#define info(message, ...)  _log(Lila::LL_INFO,  message, ##__VA_ARGS__);
#define trace(message, ...) _log(Lila::LL_TRACE, message, ##__VA_ARGS__);

#ifdef _WIN32
#define DEBUG_BREAK() __debugbreak();
#else

#define DEBUG_BREAK() __builtin_trap();
#endif

#define assertL(expr) {			\
		if(expr) {\
		} else {\
			_log(Lila::LL_ASSERT,"Assertion: %s, in file %s:%d", #expr, __FILE__, __LINE__);\
			DEBUG_BREAK();\
		}\
	}

#define assertM(expr, message) {			\
		if(expr) {\
		} else {\
			_log(Lila::LL_ASSERT,"Assertion: %s, message: %s, in file %s:%d", #expr, message, __FILE__, __LINE__);\
			DEBUG_BREAK();\
		}\
	}

}