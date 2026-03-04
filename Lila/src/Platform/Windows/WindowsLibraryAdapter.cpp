#include "Platform/LibraryAdapter.h"

#include "PlatformWindows.h"

#include "Log/Macros.h"

namespace Lila::Platform {

    LibraryAdapter::~LibraryAdapter() {
        if (!handle_m)
            return;

        if (!FreeLibrary((HMODULE)handle_m))
            LILA_FATAL("Failed to close library!");
    }

    void LibraryAdapter::loadLibrary(const std::filesystem::path& path) {
        handle_m = LoadLibraryEx(std::filesystem::absolute(path).string().c_str(), nullptr, LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);

        if (!handle_m)
            LILA_FATAL("Failed to load library: {}!", path.string());
    }

    void* LibraryAdapter::getFunctionImpl(const std::string& functionName) {
        return reinterpret_cast<void*>(GetProcAddress((HMODULE)handle_m, functionName.c_str()));
    }

} // namespace Lila::Platform
