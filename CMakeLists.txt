cmake_minimum_required(VERSION 3.20)

option(SANITIZE "Enable Address/Undefined Behavior Sanitizers" OFF)
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

# Clang
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (UNIX AND NOT APPLE)
        add_compile_options(-stdlib=libc++)
        add_link_options(-stdlib=libc++)
    endif()
endif()

# Sanitize
if(SANITIZE)
    message(STATUS "Building with sanitizers enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-omit-frame-pointer -g")
        set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address,undefined")
    elseif(MSVC)
        message(WARNING "Sanitizers not supported on MSVC yet")
    endif()
endif()

# Strict mode
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
