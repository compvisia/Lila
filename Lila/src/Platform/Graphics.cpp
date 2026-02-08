#include "Graphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Log/Macros.h"

namespace Lila::Internal {

    void initializeGlfw() {
        if (!glfwInit()) {
            LILA_FATAL("Couldn't initialize GLFW! {}", glfwGetError(nullptr));
            exit(1);
        }

        LILA_INFO("Initalized GLFW version {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
        LILA_INFO("GLFW platform {}", glfwGetPlatform());
    }

    void initializeGlad() {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            LILA_FATAL("GLAD failed to initialize!");
            exit(1);
        }

        LILA_INFO("Initalized OpenGL version {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    }

} // namespace Lila::Internal
