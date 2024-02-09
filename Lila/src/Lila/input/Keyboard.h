#pragma once

#include "Lila/core/Window.h"

#include <glfw/glfw3.h>

namespace Lila {

    class Keyboard {
    public:
        void setCallback(Window* window);

        bool isKeyDown(int key);

        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:
        static bool keys[400];
    };

}