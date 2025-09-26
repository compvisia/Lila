#pragma once

#include "Types.h"

#include "Logging/Macros.h"

#include <fstream>
#include <filesystem>

namespace Lila {

    #define EXECUTABLE_PATH std::filesystem::current_path()

    #define PROJECT_NAME "Lila"

    static std::filesystem::path getProjectPath() {
        std::filesystem::path projectPath = EXECUTABLE_PATH;
        u8 limit = 5;

        for(u8 i = 0; i < limit; i++) {
            if(projectPath.filename() == PROJECT_NAME) {
                break;
            }
            projectPath = projectPath.parent_path();
        }

        if(projectPath.filename() != PROJECT_NAME) {
            LILA_ERROR("Couldn't find project path!");
        }

        return projectPath;
    }

    static const std::filesystem::path ASSET_PATH = getProjectPath() / "Lila" / "assets";

    static std::string getContentsByPath(const std::filesystem::path& filepath) {
        if(!std::filesystem::exists(filepath)) {
            LILA_ERROR("File not found! ({})", filepath.string().c_str());
            return "";
        }

        std::ifstream file(filepath);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        return stream.str();
    }

} // namespace Lila
