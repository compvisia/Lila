cmake_minimum_required(VERSION 3.20)

project(LilaEngine)

add_executable(${PROJECT_NAME} 
    Lila/src/platform/Types.h 
    Lila/src/platform/platform.h
    Lila/src/console/ConsoleTypes.h
    Lila/src/console/Logger.h
    Lila/src/console/Logger.cpp
    Lila/src/math/math.cpp
    Lila/src/math/math.h
    Lila/src/main.cpp
)

include_directories(Lila/src)

add_subdirectory(Lila/deps/glad)
add_subdirectory(Lila/deps/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Lila/deps/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Lila/deps/glfw/src
)

target_link_libraries(${PROJECT_NAME}
    glfw
    glad
)