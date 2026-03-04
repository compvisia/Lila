#include "Platform/LibraryAdapter.h"

#include <dlfcn.h>

#include "Log/Macros.h"

namespace Lila::Platform {

    LibraryAdapter::~LibraryAdapter() {
        if (!handle_m)
            return;

        if (dlclose(handle_m) != 0)
            LILA_FATAL("Failed to close library!");
    }

    void LibraryAdapter::loadLibrary(const std::filesystem::path& path) {
        handle_m = dlopen(std::filesystem::absolute(path).string().c_str(), RTLD_LAZY | RTLD_LOCAL);

        if (!handle_m)
            LILA_FATAL("Failed to load library: {}!", path.string());
    }

    void* LibraryAdapter::getFunctionImpl(const std::string& functionName) {
        return reinterpret_cast<void*>(dlsym(handle_m, functionName.c_str()));
    }

} // namespace Lila::Platform
