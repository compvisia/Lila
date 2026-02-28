# App

set(SOURCES
    src/App.cpp
)

set(APP_NAME App)

add_library(App SHARED)

add_dependencies(App Lila)

target_sources(App PRIVATE ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(App PRIVATE Lila)

target_include_directories(App PRIVATE Source)

add_custom_command(
    TARGET App POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:App>/assets"

    COMMAND ${CMAKE_COMMAND}
        -DOUTPUT_FILE="$<TARGET_FILE_DIR:Launcher>/launchinfo.txt"
        -DLIB_NAME="${APP_NAME}"
        -DLIB_FILE="$<TARGET_FILE_NAME:App>"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/LaunchInfo.cmake"

    COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE:App>"
        "$<TARGET_FILE_DIR:Launcher>/$<TARGET_FILE_NAME:App>"

    COMMENT "Copying assets to executable directory..."
)
