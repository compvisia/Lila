#pragma once

#include <array>

#include "Event/EventBus.h"

#include "Renderer/Window.h"
#include <glfw/glfw3.h>

#include "Common/Types.h"

namespace Lila {

    struct KeyEvent {
        u32 key;
        u32 scancode;
        u32 action;
        u32 mods;
    };

    void setCallback(const Window& window, EventBus* bus);

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

} // namespace Lila
