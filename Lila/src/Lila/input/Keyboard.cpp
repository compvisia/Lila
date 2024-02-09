#include "Keyboard.h"

namespace Lila {

    bool Keyboard::keys[] = {0};

    

    void Keyboard::setCallback(Window* window) {
        glfwSetKeyCallback(window->getWindow(), Keyboard::keyCallback);
    }
    
    bool Keyboard::isKeyDown(int key) {
        return keys[key];
    }

    void Keyboard::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        keys[key] = (action != GLFW_RELEASE);
    };

    
}
