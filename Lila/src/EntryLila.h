#pragma once

#include <string>

namespace Lila {

    struct RuntimeConfig {
        std::string applicationName;
        std::string applicationLibrary;
        int argc;
        char** argv;
    };

    int Entrypoint(const RuntimeConfig& config);

} // namespace Lila
