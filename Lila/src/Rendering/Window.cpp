#include "Window.h"

#include "Logging/Macros.h"

namespace Lila {

    Window::Window(std::string windowName, const Vec2i& windowSize) {
        windowName_m = windowName;
        windowWidth_m = windowSize.x;
        windowHeight_m = windowSize.y;

        create();
    }

    Window::~Window() {
        destroy();
    }

    void Window::update() {
        glfwSwapBuffers(windowHandle_m);
        glfwPollEvents();
    }


    void Window::setSize(const Vec2i& windowSize) {
        windowWidth_m = windowSize.x;
        windowHeight_m = windowSize.y;
        glfwSetWindowSize(windowHandle_m, windowWidth_m, windowHeight_m);
    }

    Vec2i Window::getSize() const {
        return Vec2i(windowWidth_m, windowHeight_m);
    }

    GLFWwindow* Window::getHandle() {
        return windowHandle_m;
    }

    void Window::initGlad() {
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LILA_FATAL("GLAD failed to initialize!");
            exit(1);
        }

        LILA_INFO("OpenGL version {}", (const char*)glGetString(GL_VERSION));
    }

    void Window::initGlfw() {
        if(!glfwInit()) {
            LILA_FATAL("Couldn't initialize GLFW! {}", glfwGetError(nullptr));
            exit(1);
        }

        LILA_INFO("GLFW version {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
        LILA_INFO("GLFW platform {}", glfwGetPlatform());
    }

    void Window::create() {
        initGlfw();

        windowHandle_m = glfwCreateWindow(windowWidth_m, windowHeight_m, windowName_m.c_str(), NULL, NULL);

        glfwShowWindow(windowHandle_m);
        glfwFocusWindow(windowHandle_m);

        glfwMakeContextCurrent(windowHandle_m);

        initGlad();

        LILA_INFO("Window Created!");
    }

    void Window::destroy() {
        glfwDestroyWindow(windowHandle_m);
        glfwTerminate();
    }
} // namespace Lila
