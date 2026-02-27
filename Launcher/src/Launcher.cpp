#include "Log/Macros.h"
#include "EntryLila.h"

#include <sstream>
#include <string>
#include <unordered_map>

#include "Common/Filesystem.h"

// Parses the launchinfo.txt file into a key/value map.
// Default behaviour:
// - Namespaces start with [ (NOT IMPLEMENTED)
// - Lines with # are ignored
// - Keys must have values separated by '='
// - Values are single-line only
// - Keys and Values are always strings
const std::unordered_map<std::string, std::string> parseLaunchInfo(const std::string& launchInfo) {
    std::unordered_map<std::string, std::string> launchInfoMap = {};

    std::stringstream contentsStream(launchInfo);

    std::string line;
    while (std::getline(contentsStream, line)) {
        if (line.empty() || line.front() == '#')
            continue;

        if (line.back() == '\r')
            line.pop_back();

        if (line.front() == '[') { // Namespace
            LILA_ERROR("launchinfo.txt parse error: Found a namespace starter! Feature not implemented yet!");
        } else { // Key & value
            auto const equalsPosition = line.find_last_of('=');

            if (equalsPosition == std::string::npos) {
                LILA_ERROR("launchinfo.txt parse error: Couldn't find a equals sign! Line: {}", line);
                continue;
            }

            auto key = line.substr(0, equalsPosition);
            const auto value = line.substr(equalsPosition + 1);

            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);

            if (key.empty()) {
                LILA_ERROR("launchinfo.txt parse error: Key is empty! Line: {}", line);
                continue;
            }

            launchInfoMap[key] = value;
        }
    }

    return launchInfoMap;
}

int main(int argc, char** argv) {
    LILA_DEBUG("Launcher Entry");

    // TODO: Initialize critical systems (Setup environment) (AT A LATER STAGE WHEN NECESSARY)

    std::filesystem::path launchInfoFile = Lila::getExecutionPath() / "launchinfo.txt";
    std::string launchInfo = Lila::getContentsByPath(launchInfoFile);
    auto map = parseLaunchInfo(launchInfo);

    Lila::RuntimeConfig config;
    config.applicationName = map["name"];
    config.applicationLibrary = map["library"];
    config.argc = argc;
    config.argv = argv;

    // TODO: Change to a handshake (when Lila's runtime becomes a dynamic library)
    int returnCode = Lila::Entrypoint(config);

    LILA_DEBUG("Launcher Exit");

    LILA_INFO("Lila exited with code: {}", returnCode);

    return returnCode;
}
