#include "Window.h"

#include "Log/Macros.h"

namespace Lila {

    Window::Window(const WindowSpecs& windowSpecs) {
        windowSpecs_m = windowSpecs;

        create();
    }

    Window::~Window() {
        destroy();
    }

    void Window::update() {
        glfwSwapBuffers(windowHandle_m);
        glfwPollEvents();
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

        windowHandle_m = glfwCreateWindow(windowSpecs_m.width, windowSpecs_m.height, windowSpecs_m.name.c_str(), NULL, NULL);

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

    void Window::setWindowSpecs(const WindowSpecs& windowSpecs) {
        windowSpecs_m = windowSpecs;

        glfwSetWindowTitle(windowHandle_m, windowSpecs.name.c_str());
        glfwSetWindowSize(windowHandle_m, windowSpecs_m.width, windowSpecs_m.height);
    }

    WindowSpecs Window::getWindowSpecs() const {
        return windowSpecs_m;
    }

    void Window::setSize(const Vec2u& windowSize) {
        windowSpecs_m.width = windowSize.x;
        windowSpecs_m.height = windowSize.y;

        glfwSetWindowSize(windowHandle_m, windowSpecs_m.width, windowSpecs_m.height);
    }

    Vec2u Window::getSize() const {
        return Vec2u(windowSpecs_m.width, windowSpecs_m.height);
    }

    GLFWwindow* Window::getHandle() const {
        return windowHandle_m;
    }
} // namespace Lila
