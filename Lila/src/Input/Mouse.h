#pragma once

#include "Renderer/Window.h"
#include <GLFW/glfw3.h>

#include "Common/Types.h"

namespace Lila {

    struct MousePositionEvent {
        f64 x;
        f64 y;
    };

    void setMousePositionCallback(const Window& window);

    void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);

} // namespace Lila
