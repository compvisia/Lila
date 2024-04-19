#include "Keyboard.h"

#include "Lila/events/KeyboardEvent.h"

namespace Lila {

    bool Keyboard::keys[] = {0};

    void Keyboard::setCallback(GLFWwindow* window) {
        glfwSetKeyCallback(window, Keyboard::keyCallback);
    }
    
    bool Keyboard::isKeyDown(int key) {
        return keys[key];
    }

    void Keyboard::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        bool isDown = keys[key];
        keys[key] = (action != GLFW_RELEASE);

        KeyboardEvent event;
        event.setupEvent(EventType::KeyUp);
        eventhandler.releaseEvent(event);

        if(isDown != keys[key]) {
            
        }
        if(keys[key]) {
            KeyboardEvent event;
            event.setupEvent(EventType::KeyDown);
			eventhandler.releaseEvent(event);
        }
    };

    
}
