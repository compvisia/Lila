#pragma once

#include <string>

#include <GLFW/glfw3.h>

#include "Common/Types.h"

namespace Lila {

    struct WindowSpecs {
        std::string name = "Lila Application Window";
        u32 width = 1280;
        u32 height = 720;
    };

    class Window {
    public:
        Window(const WindowSpecs& windowSpecs);
        ~Window();

        void update() const;

        void setWindowSpecs(const WindowSpecs& windowSpecs);
        WindowSpecs getWindowSpecs() const;

        void setSize(u32 width, u32 height);

        u32 getWidth() const;
        u32 getHeight() const;

        GLFWwindow* getHandle() const;

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        bool isRunning() const;

    private:
        void create();
        void destroy();

    private:
        GLFWwindow* windowHandle_m;
        WindowSpecs windowSpecs_m;
    };
} // namespace Lila
