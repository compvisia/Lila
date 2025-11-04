#include "ComponentManager.h"

#include "Application/Application.h"

#include "Common/Pointers.h"

namespace Lila::ECS {

    ComponentManager& createComponentManager(Application& app) {
        if(!app.componentManager_m)
            app.componentManager_m = unique<ComponentManager>();

        return *app.componentManager_m;
    }

} // namespace Lila::ECS
