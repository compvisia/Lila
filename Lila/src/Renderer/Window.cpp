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

    void Window::update() const {
        glfwSwapBuffers(windowHandle_m);
        glfwPollEvents();
    }

    bool Window::isRunning() const {
        return !glfwWindowShouldClose(windowHandle_m);;
    }

    void Window::create() {
        windowHandle_m = glfwCreateWindow(windowSpecs_m.width, windowSpecs_m.height, windowSpecs_m.name.c_str(), NULL, NULL);

        glfwShowWindow(windowHandle_m);
        glfwFocusWindow(windowHandle_m);

        glfwMakeContextCurrent(windowHandle_m);

        LILA_INFO("Created Window")
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

    void Window::setSize(const u32 width, const u32 height) {
        windowSpecs_m.width = width;
        windowSpecs_m.height = height;

        glfwSetWindowSize(windowHandle_m, windowSpecs_m.width, windowSpecs_m.height);
    }

    u32 Window::getWidth() const {
        return windowSpecs_m.width;
    }

    u32 Window::getHeight() const {
        return windowSpecs_m.height;
    }

    GLFWwindow* Window::getHandle() const {
        return windowHandle_m;
    }
} // namespace Lila
