#include "EntryLila.h"

#include "Platform/Platform.h"

#include "Common/Pointers.h"

#include "Platform/LibraryAdapter.h"

#include "Log/Macros.h"

namespace Lila {

    int Entrypoint(const RuntimeConfig& config) {
        LILA_DEBUG("Runtime Entry");

        Unique<Platform::LibraryAdapter> adapter = unique<Platform::LibraryAdapter>();
        adapter->loadLibrary(config.applicationLibrary);

        using AppMainFunction = void(*)(int, char**);
        auto function = adapter->getFunction<AppMainFunction>("AppMain");

        if (!function) {
            LILA_FATAL("Failed to find AppMain in {}!", config.applicationLibrary);
            return -2;
        }

        AppMainFunction AppMain = *function;

        AppMain(config.argc, config.argv);

        LILA_DEBUG("Runtime Exit");

        return 0;
    };

} // namespace Lila
