#pragma once

#include "Renderer/Window.h"
#include <GLFW/glfw3.h>

#include "Common/Types.h"

namespace Lila {

    struct KeyEvent {
        u32 key;
        u32 scancode;
        u32 action;
        u32 mods;
    };

    void setKeyCallback(const Window& window);

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

} // namespace Lila
