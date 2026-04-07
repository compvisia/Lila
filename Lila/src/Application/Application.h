#pragma once

#include <string>
#include <utility>

#include "Renderer/RenderInfo.h"

#include "Common/UUID.h"

#include "Common/Pointers.h"

#include "Event/EventBus.h"
#include "ECS/ECS.h"
#include "Renderer/Window.h"
#include "World/Camera.h"

namespace Lila {
    class Application;

    EventBus& createEventBus(Application& app);
    ECS::ECS& createECS(Application& app);

    /* Application Functionality
     *
     * - Creating ECS, Renderer, Asset Manager.
     * - Multithreading. [?]
     * - Generalized Ownership Management. [?]
     */
    class Application {
    public:
        Application(const RenderProfile& profile);
        Application(const std::string &name, const RenderProfile& profile);
        ~Application();

        Application(const Application& other) = delete;
        Application& operator=(const Application& other) = delete;
        Application(Application&& other) = delete;
        Application& operator=(Application&& other) = delete;

        [[nodiscard]] const UUID& getUniqueId() const { return uuid_m; }
        [[nodiscard]] const std::string& getName() const { return name_m; }
        [[nodiscard]] const RenderProfile& getRenderProfile() const { return profile_m; }


        void setActiveCamera(ECS::Entity camera);
        ECS::Entity getActiveCamera() const { return camera_m; }

        const Window& getWindow() const { return *window_m; }
        const EventBus& getEventBus() const { return *eventBus_m; }
        const ECS::ECS& getECS() const { return *ecs_m; }

    private:
        UUID uuid_m;
        std::string name_m = "My Application";
        RenderProfile profile_m;
        ECS::Entity camera_m;

    private:
        friend EventBus& createEventBus(Application& app);
        friend ECS::ECS& createECS(Application& app);

    private:
        Unique<Window> window_m;
        Unique<EventBus> eventBus_m;
        Unique<ECS::ECS> ecs_m;
    };

} // namespace Lila
