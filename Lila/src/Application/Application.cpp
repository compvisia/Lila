#include "Application.h"

#include "Platform/Graphics.h"

#include "Log/Macros.h"

namespace Lila {

    Application::Application(const RenderProfile &profile): Application(name_m, profile) {}

    Application::Application(const std::string &name, const RenderProfile &profile) {
        name_m = name;
        profile_m = profile;

        const RenderApi api = profile_m.renderApi;

        if (api != RenderApi::None) {
            Internal::initializeGlfw();
            WindowSpecs specs;
            specs.name = name_m;
            window_m = unique<Window>(specs);
        }

        switch (api) {
            case RenderApi::OpenGL:
                Internal::initializeGlad();
                break;
            default:
                LILA_WARN("No rendering api has been given");
                break;
        }

        LILA_INFO("Created Application");
    }

    Application::~Application() = default;

    void Application::setActiveCamera(ECS::Entity camera) {
        LILA_ASSERT(ecs_m != nullptr, "setActiveCamera requires an Entity Manager to work!");

        if(ecs_m->hasComponent<CameraComponent>(camera))
            camera_m = camera;
    }


    EventBus& createEventBus(Application& app) {
        LILA_ASSERT(!app.eventBus_m, "EventBus is already created for this Application!");

        app.eventBus_m = unique<EventBus>();
        return *app.eventBus_m;
    }

    ECS::ECS& createECS(Application& app) {
        LILA_ASSERT(!app.ecs_m, "ECS is already created for this Application!");

        app.ecs_m = unique<ECS::ECS>();
        return *app.ecs_m;
    }

} // namespace Lila
