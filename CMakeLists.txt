cmake_minimum_required(VERSION 3.20)

option(STRICT_MODE "Enabled all warnings and treats them as errors" OFF)

project(Lila)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set correct output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)

# Enable Position Independent Code (needed for shared libraries)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Dependencies
include(Dependencies.cmake)

if(STRICT_MODE)
    message(STATUS "LILA ENGINE: Strict mode activated. Warnings are now errors.")

    if(MSVC)
        set(STRICT_FLAGS /W4 /WX)
    else()
        set(STRICT_FLAGS -Wall -Wextra -Werror -Wpedantic)
    endif()

    add_compile_options(${STRICT_FLAGS})
endif()

# Projects
add_subdirectory(Lila)
add_subdirectory(App)
add_subdirectory(Launcher)
