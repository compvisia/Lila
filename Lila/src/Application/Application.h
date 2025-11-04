#pragma once

#include <string>

#include "Renderer/RenderInfo.h"

#include "Common/UUID.h"

#include "Common/Pointers.h"

namespace Lila {
    class Application;
} // namespace Lila

namespace Lila::ECS {
    class ComponentManager;
    ComponentManager& createComponentManager(Application& app);
} // namespace Lila::ECS

namespace Lila {

    /* Application Functionality
     *
     * - Creating ECS, Renderer, Asset Manager.
     * - Multithreading. [?]
     * - Generalized Ownership Management. [?]
     */
    class Application {
    public:
        Application(const std::string& name, const RenderProfile& profile): name_m(name), profile_m(profile) {}
        ~Application() = default;

        Application(const Application& other) = delete;
        Application& operator=(const Application& other) = delete;
        Application(Application&& other) = delete;
        Application& operator=(Application&& other) = delete;

        const std::string& getName() const { return name_m; }

    private:
        UUID uuid_m;
        std::string name_m;
        RenderProfile profile_m;

    private:
        Unique<ECS::ComponentManager> componentManager_m;
        friend ECS::ComponentManager& ECS::createComponentManager(Application& app);

    };
    
} // namespace Lila
