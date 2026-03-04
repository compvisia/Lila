#pragma once

#include <string>
#include <filesystem>
#include <functional>
#include <expected>

#include "Common/Pointers.h"

namespace Lila::Platform {

    class LibraryAdapter {
    public:
        LibraryAdapter() = default;
        virtual ~LibraryAdapter();

        void loadLibrary(const std::filesystem::path& path);

    private:
        void* getFunctionImpl(const std::string& functionName);

    public:
        // TODO: Change std::string to proper error
        template<typename T>
        std::expected<T, std::string> getFunction(const std::string& functionName) {
            void* function = getFunctionImpl(functionName);

            if (function)
                return reinterpret_cast<T>(function);

            return std::unexpected<std::string>{"Function not found: " + functionName};
        }

    private:
        void* handle_m;
    };

} // namespace Lila::Platform
