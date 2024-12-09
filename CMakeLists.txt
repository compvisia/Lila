cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

project(LilaEngine)

add_executable(${PROJECT_NAME} 
    Lila/src/console/ConsoleTypes.h
    Lila/src/console/Logger.cpp
    Lila/src/console/Logger.h

    Lila/src/core/Window.cpp
    Lila/src/core/Window.h

    Lila/src/ecs/Component.h
    Lila/src/ecs/ComponentHandler.h
    Lila/src/ecs/ComponentPool.h
    Lila/src/ecs/Entity.h
    Lila/src/ecs/Registry.cpp
    Lila/src/ecs/Registry.h
    Lila/src/ecs/System.h
    Lila/src/ecs/SystemHandler.h

    Lila/src/math/math.cpp
    Lila/src/math/math.h
    Lila/src/math/matrix4.cpp
    Lila/src/math/matrix4.h
    Lila/src/math/vec2.h
    Lila/src/math/vec3.h
    Lila/src/math/vec4.h

    Lila/src/platform/filesystem.h
    Lila/src/platform/platform.h
    Lila/src/platform/Types.h 
    
    Lila/src/renderer/OpenGL/GLGeometry.cpp
    Lila/src/renderer/OpenGL/GLGeometry.h
    Lila/src/renderer/OpenGL/GLShader.cpp
    Lila/src/renderer/OpenGL/GLShader.h

    Lila/src/renderer/Camera.h
    Lila/src/renderer/Geometry.h
    Lila/src/renderer/Perspective.cpp
    Lila/src/renderer/Perspective.h
    Lila/src/renderer/Shader.h

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