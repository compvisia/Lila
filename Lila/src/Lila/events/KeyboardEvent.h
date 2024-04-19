#pragma once

#include "Lila/input/Keyboard.h"

#include "Event.h"

namespace Lila {

    class KeyboardEvent : public Event {
    public:

        KeyboardEvent* setupEvent(EventType type) { type_m = type; category_m = EventCategory::Category_Keyboard; return this; }

        KeyboardEvent* setKeyboard(Keyboard keyboard) { keyboard_m = keyboard; return this; }
        Keyboard getKeyboard() { return keyboard_m; }
    
    private:
        Keyboard keyboard_m;
    };
}