cmake_minimum_required(VERSION 3.20)

project(Lila)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
include(Dependencies.cmake)

# Projects
add_subdirectory(Lila)
add_subdirectory(App)
