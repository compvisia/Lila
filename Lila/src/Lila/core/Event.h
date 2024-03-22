#pragma once

#include <vector>

namespace Lila {

    
    enum class EventType {
        None = 0,
        AppCreated, AppDestroyed, AppUpdate, AppRender,
        
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased,
        MouseMoved, MouseScrolled,
        
        NewInputDevice, LostInputDevice,
        NewAudioDevice, LostAudioDevice,
        
        WindowCreated, WindowDestroyed, WindowResized, WindowMoved
    };

    class Event {
    public:
        Event(EventType type) { type_m = type; }

        EventType getEventType() { return type_m; }


        bool handled = false;
        
    private:
        EventType type_m;
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
                for(Listener* l : listeners)
                    l->onEvent(event);
            }
        }

    private:
        std::vector<Listener*> listeners;
    };

    static EventHandler eventhandler;

}