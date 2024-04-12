#pragma once

#include "Lila/core/Application.h"

#include "Event.h"

namespace Lila {

    class AppEvent : public Event {
    public:
        AppEvent(Application* app) { app_m = app; type_m = type; category_m = EventCategory::Category_Application; }

        Application* getApp() { return app_m; }
    
    private:
        Application* app_m;
    };
}