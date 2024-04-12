#pragma once

#include "Lila/input/Mouse.h"

#include "Event.h"

namespace Lila {

    class MouseEvent : public Event {
    public:
        MouseEvent(Mouse mouse, EventType type) { mouse_m = mouse; type_m = type; category_m = EventCategory::Category_Mouse; }

        Mouse getMouse() { return mouse; }
    
    private:
        Mouse mouse_m;
    };
}