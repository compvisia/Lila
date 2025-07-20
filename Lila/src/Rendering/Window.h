#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Math/Vec2.h"

#include "Common/Types.h"

namespace Lila {

    class Window {
    public:
        Window(std::string windowName, const Vec2i& windowSize);
        ~Window();

        void update();

        void setSize(const Vec2i& windowSize);
        Vec2i getSize() const;

        GLFWwindow* getHandle();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

    private:
        void initGlad();
        void initGlfw();

        void create();
        void destroy();

    private:
        GLFWwindow* windowHandle_m;
        std::string windowName_m;
        u32 windowWidth_m;
        u32 windowHeight_m;
    };
} // namespace Lila
