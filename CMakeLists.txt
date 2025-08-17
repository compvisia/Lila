cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(LilaEngine)

add_executable(${PROJECT_NAME}
    Lila/src/Common/Filesystem.h
    Lila/src/Common/Pointers.h
    Lila/src/Common/Types.h

    Lila/src/ECS/ComponentManager.h
    Lila/src/ECS/Components.h
    Lila/src/ECS/Entity.h
    Lila/src/ECS/EntityManager.cpp
    Lila/src/ECS/EntityManager.h
    Lila/src/ECS/SparseSet.h

    Lila/src/Logging/LogLevel.h
    Lila/src/Logging/Logger.cpp
    Lila/src/Logging/Logger.h
    Lila/src/Logging/Macros.h

    Lila/src/Math/Vec2.h
    Lila/src/Math/Vec3.h
    Lila/src/Math/Vec4.h

    Lila/src/Platform/Platform.h

    Lila/src/Rendering/OpenGL/GLGeometry.cpp
    Lila/src/Rendering/OpenGL/GLGeometry.h
    Lila/src/Rendering/OpenGL/GLShader.cpp
    Lila/src/Rendering/OpenGL/GLShader.h
    Lila/src/Rendering/Geometry.h
    Lila/src/Rendering/Shader.h
    Lila/src/Rendering/Window.cpp
    Lila/src/Rendering/Window.h

    Lila/src/main.cpp
)

include_directories(Lila/src)

add_subdirectory(Lila/deps/glad)
add_subdirectory(Lila/deps/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC Lila/deps/glfw/include
    PUBLIC Lila/deps/stb
)

target_link_directories(${PROJECT_NAME}
    PRIVATE Lila/deps/glfw/src
)

target_link_libraries(${PROJECT_NAME}
    glfw
    glad
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
