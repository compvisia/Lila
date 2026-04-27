#include "Mouse.h"

#include "Event/EventBus.h"

namespace Lila {

    void setMousePositionCallback(const Window& window) {
        glfwSetCursorPosCallback(window.getHandle(), mousePositionCallback);
    }

    void mousePositionCallback(GLFWwindow* window, double xpos, double ypos) {
        EventBus* bus = (EventBus*)glfwGetWindowUserPointer(window);

        MousePositionEvent event = {
            (f64)xpos,
            (f64)ypos
        };

        bus->emit<MousePositionEvent>(event);
    }

} // namespace Lila
