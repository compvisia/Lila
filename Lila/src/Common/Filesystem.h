#pragma once

#include <filesystem>
#include <fstream>
#include <string>

#include "Log/Macros.h"

#include "Platform/Platform.h"

#ifdef LILA_PLATFORM_WINDOWS
    extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameW(void* hModule, wchar_t* lpFilename, unsigned long nSize);
#elif LILA_PLATFORM_LINUX
    #include <linux/limits.h>
    #include <unistd.h>
    #include <system_error>
#else
    #error "Unsupported platform: Cannot determine executable path."
#endif

namespace Lila {

    inline std::filesystem::path getExecutionPath() {
        #if defined(_WIN32)
            wchar_t path[32768] = {0};

            if (GetModuleFileNameW(NULL, path, sizeof(path) / sizeof(wchar_t)) == 0) {
                LILA_FATAL("Could not get execution path!");
                return ""; // TODO: Fix error state
            }

            return std::filesystem::path(path).parent_path();
        #elif defined(__linux__)
            std::error_code errorCode;

            std::filesystem::path execPath = std::filesystem::read_symlink("/proc/self/exe", errorCode);

            if (errorCode) {
                LILA_FATAL("Could not get execution path: {}", errorCode.message());
                return ""; // TODO: Fix error state
            }

            return execPath.parent_path();
        #else
            #error "Unsupported platform"
        #endif
    }

    inline std::filesystem::path getAssetPath() {
       return getExecutionPath() / "assets";
    }

    inline std::string getContentsByPath(const std::filesystem::path& filepath) {
        if (!std::filesystem::exists(filepath)) {
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
