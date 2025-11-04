# Dependencies

include(FetchContent)

# GLFW
find_package(glfw3 3.4 QUIET)

if (NOT glfw3_FOUND)
    set(GLFW_BUILD_WAYLAND OFF)
    FetchContent_Declare(
            glfw3
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/compvisia/glfw/archive/refs/heads/master.zip
    )

    FetchContent_GetProperties(glfw3)

    if (NOT glfw3_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(glfw3)
    endif()
endif()

# OpenGL / GLAD
find_package(OpenGL REQUIRED)

FetchContent_Declare(
    glad
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/compvisia/glad/archive/refs/heads/master.zip
)

FetchContent_GetProperties(glad)

if(NOT glad_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(glad)
endif()

set_target_properties(glad PROPERTIES FOLDER "Dependencies")

# glm
FetchContent_Declare(
    glm
    GIT_REPOSITORY	https://github.com/g-truc/glm.git
    GIT_TAG a532f5b1cf27d6a3c099437e6959cf7e398a0a67
)

FetchContent_MakeAvailable(glm)
