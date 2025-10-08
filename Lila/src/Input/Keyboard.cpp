#include "Keyboard.h"

namespace Lila {

    void setCallback(const Window& window, EventBus* bus) {
        glfwSetWindowUserPointer(window.getHandle(), bus);
        glfwSetKeyCallback(window.getHandle(), keyCallback);
    }

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto* bus = (EventBus*)glfwGetWindowUserPointer(window);

        KeyEvent event = {
            (u32)key,
            (u32)scancode,
            (u32)action,
            (u32)mods
        };

        bus->emit<KeyEvent>(event);
    }


}
