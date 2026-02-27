#include "EntryLila.h"

#include "Platform/Platform.h"

#ifdef LILA_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#ifdef ERROR
#undef ERROR
#endif
#ifdef DELETE
#undef DELETE
#endif
#elif LILA_PLATFORM_LINUX
#include <dlfcn.h>
#endif

#include "Log/Macros.h"

namespace Lila {

    int Entrypoint(const RuntimeConfig& config) {
        LILA_DEBUG("Runtime Entry");

        // TODO: Cleanup
        using AppMainFunction = void(*)(int, char**);
        AppMainFunction AppMain;
#ifdef LILA_PLATFORM_WINDOWS
        auto handle = LoadLibrary(config.applicationLibrary.c_str());

        if (!handle) {
            LILA_FATAL("Failed to load library: {}!", config.applicationLibrary);
        }

        AppMain = (AppMainFunction)GetProcAddress(handle, "AppMain");

#elif defined(LILA_PLATFORM_LINUX)
        auto handle = dlopen(config.applicationLibrary.c_str(), RTLD_NOW | RTLD_LOCAL);;

        if (!handle) {
            LILA_FATAL("Failed to load library: {}!", config.applicationLibrary);
        }

        AppMain = (AppMainFunction)dlsym(handle, "AppMain");
#else
        LILA_FATAL("Operating system not implemented yet!");
#endif

        if (!AppMain) {
            LILA_FATAL("Failed to find AppMain in {}!", config.applicationLibrary);
            return -2;
        }

        AppMain(config.argc, config.argv);

#ifdef LILA_PLATFORM_WINDOWS
        if (FreeLibrary(handle) == 0) {
            LILA_FATAL("Failed to close library! {}", GetLastError());
        }
#elif defined(LILA_PLATFORM_LINUX)
        if (dlclose(handle) != 0) {
            LILA_FATAL("Failed to close library!");
        }
#else
        LILA_FATAL("Operating system not implemented yet!");
#endif

        LILA_DEBUG("Runtime Exit");

        return 0;
    };

} // namespace Lila
