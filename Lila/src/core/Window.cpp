#include "Window.h"

#include "console/Logger.h"

namespace Lila {

Window::Window(str name, u32 width, u32 height) {
    name_m = name;
    width_m = width;
    height_m = height;

    create();
}

Window::~Window() {
    destroy();
}

void Window::destroy() {
    glfwDestroyWindow(windowPtr_m);
    glfwTerminate();
}

void Window::create() {
    if(!glfwInit()) {
        LOG_FATAL("Couldn't initialize GLFW! Code: %x (program must exit)", glfwGetError(nullptr));
        exit(1);
    }

    LOG_INFO("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
    LOG_INFO("GLFW platform %d", glfwGetPlatform());

    windowPtr_m = glfwCreateWindow(width_m, height_m, name_m.c_str(), NULL, NULL);

    fullscreen_m = false;
    maximized_m = false;

    monitor_m = glfwGetWindowMonitor(windowPtr_m);

    glfwShowWindow(windowPtr_m);
    glfwFocusWindow(windowPtr_m);

    glfwMakeContextCurrent(windowPtr_m);

    LOG_INFO("Window Created!");
}

GLFWwindow* Window::getPointer() {
    return windowPtr_m;
}

}