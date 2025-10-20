#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Math/Vec2.h"

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

        void update();

        void setWindowSpecs(const WindowSpecs& windowSpecs);
        WindowSpecs getWindowSpecs() const;

        void setSize(const Vec2u& windowSize);
        Vec2u getSize() const;

        GLFWwindow* getHandle() const;

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

    private:
        void initGlad();
        void initGlfw();

        void create();
        void destroy();

    private:
        GLFWwindow* windowHandle_m;
        WindowSpecs windowSpecs_m;
    };
} // namespace Lila
