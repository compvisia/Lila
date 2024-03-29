#include "Application.h"

namespace Lila {

    void Application::init() {
        if(specs.headless) {
            info("%s is a headless application", specs.name.c_str());
            warn("GLFW and OpenGL will not be initialized");
            return;
        }
        
        window = std::make_unique<Window>("Window", specs.width, specs.height);
    }

    void Application::destroy() {

        
    }
}