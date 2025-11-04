# Lila Engine

set(SOURCES
    src/Application/Application.cpp
    src/Application/Application.h

    src/Common/Filesystem.h
    src/Common/Pointers.h
    src/Common/Types.h
    src/Common/UUID.h
    src/Common/UUID.cpp

    src/ECS/ComponentManager.h
    src/ECS/Components.h
    src/ECS/Entity.h
    src/ECS/EntityManager.cpp
    src/ECS/EntityManager.h
    src/ECS/SparseSet.h

    src/Event/EventBus.h

    src/Input/Keyboard.cpp
    src/Input/Keyboard.h
    src/Input/Mouse.cpp
    src/Input/Mouse.h

    src/Log/LogLevel.h
    src/Log/Logger.h
    src/Log/Macros.h

    src/Math/Matrix.h
    src/Math/Quaternion.h
    src/Math/Vec2.h
    src/Math/Vec3.h
    src/Math/Vec4.h

    src/Platform/Platform.h

    src/Renderer/OpenGL/GLGeometry.cpp
    src/Renderer/OpenGL/GLGeometry.h
    src/Renderer/OpenGL/GLShader.cpp
    src/Renderer/OpenGL/GLShader.h
    src/Renderer/OpenGL/GLTexture.cpp
    src/Renderer/OpenGL/GLTexture.h
    src/Renderer/Geometry.h
    src/Renderer/RenderInfo.h
    src/Renderer/Shader.h
    src/Renderer/Texture.h
    src/Renderer/Window.cpp
    src/Renderer/Window.h

    src/World/Camera.cpp
    src/World/Camera.h
)

add_library(Lila STATIC)

target_sources(Lila PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Lila
    glfw
    glad
    glm
)

target_include_directories(Lila PUBLIC "src" "deps/stb")
