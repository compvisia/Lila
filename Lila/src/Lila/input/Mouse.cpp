#include "Mouse.h"

namespace Lila {

    bool Mouse::buttons[] = {0};
    Vec2 Mouse::pos = Vec2(0,0);
    Vec2 Mouse::offset = Vec2(0,0);
    bool Mouse::entered = false;

    void Mouse::setCallback(Window* window) {
        glfwSetMouseButtonCallback(window->getWindow(), Mouse::buttonCallback);
        glfwSetCursorPosCallback(window->getWindow(), Mouse::posCallback);
        glfwSetScrollCallback(window->getWindow(), Mouse::scrollCallback);
        glfwSetCursorEnterCallback(window->getWindow(), Mouse::enterCallback);
    }

    
    bool Mouse::isButtonDown(int button) {
        return buttons[button];
    }

    Vec2 Mouse::getPosition() {
        return pos;
    }

    Vec2 Mouse::getScroll() {
        return offset;
    }

    bool Mouse::hasEntered() {
        return entered;
    }


    void Mouse::buttonCallback(GLFWwindow* window, int button, int action, int mods) {
        buttons[button] = (GLFW_RELEASE != action);
    }

    void Mouse::posCallback(GLFWwindow* window, double xpos, double ypos) {
        pos.setX((float)xpos);
        pos.setY((float)ypos);
    }
    
    void Mouse::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
        offset.setX((float)xoffset);
        offset.setY((float)yoffset);
    }
    
    void Mouse::enterCallback(GLFWwindow* window, int entered) {
        Mouse::entered = entered;
    }
}
