#pragma once

#include "Lila/core/Window.h"

#include "Lila/core/Core.h"

namespace Lila {

    class Keyboard {
    public:
        void setCallback(GLFWwindow* window);

        bool isKeyDown(int key);

        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:
        static bool keys[400];
    };

}