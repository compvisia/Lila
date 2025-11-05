#include "Application.h"

#include "Platform/Graphics.h"

#include "Log/Macros.h"

namespace Lila {

    Application::Application(const RenderProfile &profile): Application(name_m, profile) {}

    Application::Application(const std::string &name, const RenderProfile &profile) {
        name_m = name;
        profile_m = profile;

        const RenderApi api = profile_m.renderApi;
        switch(api) {
            case RenderApi::OpenGL: {
                Internal::initializeGlfw();
                WindowSpecs specs;
                specs.name = name_m;
                window_m = unique<Window>(specs);
                Internal::initializeGlad();
                break;
            }
            case RenderApi::None: {
                window_m = nullptr;
                break;
            }
        }

        LILA_INFO("Created Application")
    }

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
