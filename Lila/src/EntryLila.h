#pragma once

#include <string>

namespace Lila {

    struct RuntimeConfig {
        std::string name;
        std::string libraryFile;
        std::string entryName;
        int argc;
        char** argv;
    };

    int Entrypoint(const RuntimeConfig& config);

} // namespace Lila
