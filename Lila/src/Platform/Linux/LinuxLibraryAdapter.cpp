#include "Platform/LibraryAdapter.h"

#include <dlfcn.h>

namespace Lila::Platform {

    LibraryAdapter::~LibraryAdapter() {
        if (!handle_m)
            return;

        if (dlclose(handle) != 0)
            LILA_FATAL("Failed to close library!");
    }

    void LibraryAdapter::loadLibrary(const std::filesystem::path& path) {
        handle_m = dlopen(std::filesystem::weakly_canonical(path).string().c_str());

        if (!handle_m)
            LILA_FATAL("Failed to load library: {}!", path.string());
    }

    void* LibraryAdapter::getFunctionImpl(const std::string& functionName) {
        return reinterpret_cast<void*>(dlsym(handle_m, functionName.c_str()));
    }

} // namespace Lila::Platform
