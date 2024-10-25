cmake_minimum_required(VERSION 3.20)

project(LilaEngine)

add_executable(${PROJECT_NAME} Lila/src/main.cpp)

add_subdirectory(Lila/deps/glfw)

add_subdirectory(Lila/deps/glad)

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