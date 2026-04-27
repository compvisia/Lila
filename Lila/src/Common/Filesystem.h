#pragma once

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <expected>

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

    using FilesystemError = std::string;

    inline std::expected<std::filesystem::path, FilesystemError> getExecutionPath() {
        #if defined(_WIN32)
            wchar_t path[32768] = {0};

            if (GetModuleFileNameW(NULL, path, sizeof(path) / sizeof(wchar_t)) == 0) {
                return std::unexpected<FilesystemError>{
                    "Could not get execution path!"
                };
            }

            return std::filesystem::path(path).parent_path();
        #elif defined(__linux__)
            std::error_code errorCode;

            std::filesystem::path execPath = std::filesystem::read_symlink("/proc/self/exe", errorCode);

            if (errorCode) {
                return std::unexpected<FilesystemError>{
                    "Could not get execution path: " + errorCode.message()
                };
            }

            return execPath.parent_path();
        #else
            #error "Unsupported platform"
        #endif
    }

    inline std::expected<std::filesystem::path, FilesystemError> getAssetPath() {
        std::expected<std::filesystem::path, FilesystemError> path = getExecutionPath();
        if (!path)
            return std::unexpected<FilesystemError>{path.error()};

        return *path / "assets";
    }

    inline std::expected<std::string, FilesystemError> getContentsByPath(const std::filesystem::path& filepath) {
        if (!std::filesystem::exists(filepath)) {
            return std::unexpected<FilesystemError>{
                "File not found: " + filepath.string()
            };
        }

        std::ifstream file(filepath);

        if (!file.is_open()) {
            return std::unexpected<FilesystemError>{
                "Could not open file: " + filepath.string()
            };
        }

        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        return stream.str();
    }

} // namespace Lila
