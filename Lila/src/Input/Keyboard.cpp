#include "Keyboard.h"

#include "Event/EventBus.h"

namespace Lila {

    void setKeyCallback(const Window& window) {
        glfwSetKeyCallback(window.getHandle(), keyCallback);
    }

    void keyCallback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods) {
        auto* bus = static_cast<EventBus*>(glfwGetWindowUserPointer(window));

        const KeyEvent event = {
            (u32)key,
            (u32)scancode,
            (u32)action,
            (u32)mods
        };

        bus->emit<KeyEvent>(event);
    }


}
