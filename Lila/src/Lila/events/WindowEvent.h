#pragma once

#include "Event.h"
#include "Lila/core/Window.h"

namespace Lila {

    class WindowEvent : public Event {
    public:

        void setWindow(Window window) { window_m = window; }
        Window getWindow() { return window_m; }
    
    private:
        Window window_m;
    };

}