#pragma once

#include <string>
#include <utility>

#include "Renderer/RenderInfo.h"

#include "Common/UUID.h"

#include "Common/Pointers.h"

#include "Event/EventBus.h"
#include "ECS/ComponentManager.h"
#include "ECS/EntityManager.h"

namespace Lila {
    class Application;

    EventBus& createEventBus(Application& app);
    ECS::EntityManager& createEntityManager(Application& app);
    ECS::ComponentManager& createComponentManager(Application& app);

    /* Application Functionality
     *
     * - Creating ECS, Renderer, Asset Manager.
     * - Multithreading. [?]
     * - Generalized Ownership Management. [?]
     */
    class Application {
    public:
        Application(const RenderProfile& profile): profile_m(profile) {}
        Application(std::string name, const RenderProfile& profile): name_m(std::move(name)), profile_m(profile) {}
        ~Application();

        Application(const Application& other) = delete;
        Application& operator=(const Application& other) = delete;
        Application(Application&& other) = delete;
        Application& operator=(Application&& other) = delete;

        [[nodiscard]] const UUID& getUniqueId() const { return uuid_m; }
        [[nodiscard]] const std::string& getName() const { return name_m; }
        [[nodiscard]] const RenderProfile& getRenderProfile() const { return profile_m; }

        const EventBus& getEventBus() const { return *eventBus_m; }
        const ECS::EntityManager& getEntityManager() const { return *entityManager_m; }
        const ECS::ComponentManager& getComponentManager() const { return *componentManager_m; }

    private:
        UUID uuid_m;
        std::string name_m = "My Application";
        RenderProfile profile_m;

    private:
        friend EventBus& createEventBus(Application& app);
        friend ECS::EntityManager& createEntityManager(Application& app);
        friend ECS::ComponentManager& createComponentManager(Application& app);

    private:
        Unique<EventBus> eventBus_m;
        Unique<ECS::EntityManager> entityManager_m;
        Unique<ECS::ComponentManager> componentManager_m;
    };


    
} // namespace Lila
