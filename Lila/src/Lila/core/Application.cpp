#include "Application.h"

namespace Lila {

    void Application::init() {
        if(specs.headless) {
            lila_info("%s is a headless application", specs.name.c_str());
            lila_warn("GLFW and OpenGL will not be initialized");
            return;
        }
        
        window = createRef<Window>("Window", specs.width, specs.height);
    }

    void Application::destroy() {

        
    }
}