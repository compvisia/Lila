#pragma once

#include "Lila/core/Window.h"

#include <glfw/glfw3.h>

namespace Lila {

    class Mouse {
    public:
        void setCallback(Window* window);

        bool isButtonDown(int button);
        Vec2 getPosition();
        bool hasEntered();

        static void buttonCallback(GLFWwindow* window, int button, int action, int mods);
        static void posCallback(GLFWwindow* window, double xpos, double ypos);
        static void scroCallback(GLFWwindow* window, int entered);
        static void enterCallback(GLFWwindow* window, int entered);

    private:
        static bool buttons[8];
        static Vec2 pos;
        static bool entered;
    };

}