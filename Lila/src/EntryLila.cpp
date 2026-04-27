#include "EntryLila.h"

#include <expected>

#include "Common/Pointers.h"

#include "Platform/LibraryAdapter.h"

#include "Log/Macros.h"

namespace Lila {

    int Entrypoint(const RuntimeConfig& config) {
        LILA_DEBUG("Runtime Entry");

        Unique<Platform::LibraryAdapter> adapter = unique<Platform::LibraryAdapter>();
        adapter->loadLibrary(config.libraryFile);

        using EntryFunction = void(*)(int, char**);
        std::expected<EntryFunction, std::string> function = adapter->getFunction<EntryFunction>(config.entryName);

        if (!function) {
            LILA_FATAL(function.error());
            return -2;
        }

        EntryFunction entry = *function;

        entry(config.argc, config.argv);

        LILA_DEBUG("Runtime Exit");

        return 0;
    };

} // namespace Lila
