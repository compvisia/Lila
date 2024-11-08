#include "Logger.h"

#include <iostream>
#include <cstdarg>

namespace Lila {

    void Logger::log(const LogLevel& logLevel, const str fmt, ...) {
        const str prefixes[] = {
            "\x1b[31m[FATAL] :",        
            "\x1b[91m[ERROR] :",
            "\x1b[93m[WARN]  :",
            "\x1b[94m[INFO]  :",
            "\x1b[96m[DEBUG] :",
            "\x1b[35m[TRACE] :",
            "\x1b[92m[FUNC]  :",
        };

        printf("%s ", prefixes[logLevel].c_str());

        va_list arguments;

        #ifdef LILA_PLATFORM_WINDOWS
			__crt_va_start(arguments, fmt);
			vprintf(fmt.c_str(), arguments);
			__crt_va_end(arguments);
		#elif LILA_PLATFORM_LINUX
			__builtin_va_start(arguments, fmt);
			vprintf(fmt.c_str(), arguments);
			__builtin_va_end(arguments);
		#else
			va_start(arguments, fmt);
			vprintf(fmt.c_str(), arguments);
			va_end(arguments);
		#endif

        printf("\033[0m\n");
    }
}