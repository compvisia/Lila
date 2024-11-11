#pragma once

#include "types.h"

#include "console/Logger.h"

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
        LOG_ERROR("Couldn't find project path!");
    }

    return projectPath;
}

} // namespace fs
