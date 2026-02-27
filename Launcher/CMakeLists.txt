# Lila Launcher

set(SOURCES
    src/Launcher.cpp
)

add_executable(Launcher)

add_dependencies(Launcher Lila)

target_sources(Launcher PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Launcher PRIVATE Lila)

target_include_directories(Launcher PRIVATE
    ${CMAKE_SOURCE_DIR}/Lila
)
