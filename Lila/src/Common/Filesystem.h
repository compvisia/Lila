#pragma once

#include <filesystem>
#include <fstream>
#include <string>

#include "Log/Macros.h"

#ifdef _WIN32
    extern "C" __declspec(dllimport)
    unsigned long __stdcall GetModuleFileNameW(void* hModule, wchar_t* lpFilename, unsigned long nSize);
#elif defined(__linux__)
    #include <linux/limits.h>
    #include <unistd.h>
    #include <system_error>
#else
    #error "Unsupported platform: Cannot determine executable path."
#endif

namespace Lila {

    static std::filesystem::path getExecutionPath() {
        #if defined(_WIN32)
            wchar_t path[32768] = {0};

            if(GetModuleFileNameW(NULL, path, sizeof(path) / sizeof(wchar_t)) == 0) {
                LILA_FATAL("Could not get execution path!");
                return "";
            }

            return std::filesystem::path(path).parent_path();
        #elif defined(__linux__)
            char path[PATH_MAX] = {0};

            std::error_code errorCode;

            std::filesystem::path path = std::filesystem::read_symlink("/proc/self/exe", ec);

            if(ec) {
                LILA_FATAL("Could not get execution path: {}", errorCode.message());
                return "";
            }

            return path.parent_path();
        #else
            #error "Unsupported platform"
        #endif
    }

    static std::filesystem::path getAssetPath() {
       return getExecutionPath() / "assets";
    }

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
