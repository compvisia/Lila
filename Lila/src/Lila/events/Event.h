#pragma once

#include "Lila/core/Core.h"

#include <vector>

namespace Lila {

    
    enum class EventType {
        None = 0,
        AppCreated, AppDestroyed, AppUpdate, AppRender,
        
        KeyDown, KeyUp,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        
        NewInputDevice, LostInputDevice,
        NewAudioDevice, LostAudioDevice,
        
        WindowCreated, WindowDestroyed, WindowResized, WindowMoved
    };

    enum class EventCategory {
        None = 0,
        Category_Application = lila_bit(0),

        Category_Keyboard    = lila_bit(1),
        Category_Mouse       = lila_bit(2),
        
        Category_InputDevice = lila_bit(3),
        Category_AudioDevice = lila_bit(4),
        
        Category_Window      = lila_bit(5)
    };

    class Event {
    public:
        EventType getEventType()         { return type_m; }
        EventCategory getEventCategory() { return category_m; }


        bool handled = false;
        
    protected:
        EventType type_m;
        EventCategory category_m;
    };


    class Listener {
    public:
        Listener() {}

        virtual void onEvent(Event& event) = 0;

    };

    class EventHandler {
    public:
        EventHandler() {}

        void addListener(Listener* listener) { listeners.push_back(listener); }

        void releaseEvent(Event& event) {
            if(!event.handled) {
                event.handled = true;
                for(Listener* l : listeners) {
                    l->onEvent(event);
                }
            }
        }

    private:
        std::vector<Listener*> listeners;
    };

    static EventHandler eventhandler;

}