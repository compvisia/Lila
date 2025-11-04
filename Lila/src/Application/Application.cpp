#include "Application.h"

#include "Log/Macros.h"

namespace Lila {

    Application::~Application() = default;

    EventBus& createEventBus(Application& app) {
        LILA_ASSERT(!app.eventBus_m, "EventBus is already created for this Application!");
        app.eventBus_m = unique<EventBus>();
        return *app.eventBus_m;
    }

    ECS::EntityManager& createEntityManager(Application& app) {
        LILA_ASSERT(!app.entityManager_m, "EntityManager is already created for this Application!");
        app.entityManager_m = unique<ECS::EntityManager>();
        return *app.entityManager_m;
    }

    ECS::ComponentManager& createComponentManager(Application& app) {
        LILA_ASSERT(!app.componentManager_m, "ComponentManager is already created for this Application!");
        app.componentManager_m = unique<ECS::ComponentManager>();
        return *app.componentManager_m;
    }
    
} // namespace Lila
