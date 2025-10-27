#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer/OpenGL/GLGeometry.h"
#include "Renderer/OpenGL/GLShader.h"

#include "Common/Pointers.h"
#include "Common/Types.h"
#include "Log/Macros.h"

#include "Renderer/Window.h"

#include "ECS/Entity.h"
#include "ECS/EntityManager.h"
#include "ECS/Components.h"
#include "ECS/ComponentManager.h"

#include "Event/EventBus.h"

#include "Input/Keyboard.h"

#include "World/Camera.h"

struct Transform {
    f32 x, y, z;
};

struct Tag {
    u64 tag;
};

f32 camX = 0, camY = 0, camZ = 0;
f32 camSpeed = 0.05;
b8 disconnectSubscription = false;

void keyEventFunction(Lila::KeyEvent event) {
    if(event.key == 65)
        camZ -= camSpeed;
    if(event.key == 68)
        camZ += camSpeed;

    if(event.key == 340)
        camY -= camSpeed;
    if(event.key == 32)
        camY += camSpeed;

    if(event.key == 87)
        camX += camSpeed;
    if(event.key == 83)
        camX -= camSpeed;

    if(event.key == 82) // R
        disconnectSubscription = true;
}


int main() {
    // C++ Version
    #ifdef _MSVC_LANG
    LILA_INFO("C++ version {}", _MSVC_LANG)
    #elif defined(__cplusplus)
    LILA_INFO("C++ version {}", __cplusplus)
    #else
    LILA_WARN("Failed identify C++ version")
    #endif

    // Compiler Version
    #ifdef _MSC_VER
    LILA_INFO("MSVC version {}", _MSC_VER)
    #elif defined(__GNUC__)
    LILA_INFO("GNU g++ version {}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
    #elif defined(__clang__)
    LILA_INFO("LLVM clang version {}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__)
    #else
    LILA_WARN("Failed identify C++ compiler")
    #endif

    Lila::WindowSpecs windowSpecs;

    Lila::Window window = Lila::Window(windowSpecs);

    // TODO: Define inside an engine system manager.
    Lila::EventBus bus;

    /* <-- IMPORTANT -->
     * Lila::EventBus::subscribe returns a EventSubscription object.
     * This EventSubscription object MUST be captured by using a variable, else the subscription will be invalidated.
     * When the subscription goes out of scope, or when calling disconnect(), the object will automatically disconnect.
     */
    auto sub = bus.subscribe<Lila::KeyEvent>(keyEventFunction);

    Lila::setCallback(window, &bus);

    std::vector<f32> vertices {
        -1, -1,  1,
         1, -1,  1,
        -1,  1,  1,
         1,  1,  1,
        -1, -1, -1,
         1, -1, -1,
        -1,  1, -1,
         1,  1, -1
    };
    std::vector<u32> indices {
        2, 6, 7,
        2, 3, 7,
        0, 4, 5,
        0, 1, 5,
        0, 2, 6,
        0, 4, 6,
        1, 3, 7,
        1, 5, 7,
        0, 2, 3,
        0, 1, 3,
        4, 6, 7,
        4, 5, 7
    };

    Unique<OpenGL::GLGeometry> geometry = unique<OpenGL::GLGeometry>(vertices, indices);
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(Lila::getAssetPath() / "default.vert", Lila::getAssetPath() / "default.frag");

    /*
     * ECS Example
     */
    Lila::ECS::EntityManager em;
    Lila::ECS::ComponentManager cm;

    cm.registerComponent<Lila::CameraComponent>();

    Lila::ECS::Entity camera = em.createEntity();

    cm.addComponent(camera, Lila::CameraComponent{});

    glm::mat4 view = glm::lookAt(glm::vec3(-4.0f, 3.0f, -2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window.getHandle())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

		view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		shader->bind();

        shader->uniformMatrix(
            "projection",
            Lila::getProjection(cm.getComponent<Lila::CameraComponent>(camera))
        );

        shader->uniformMatrix(
            "view",
            view
        );

        if(disconnectSubscription) {
            sub.disconnect();
            disconnectSubscription = false;
        }

        geometry->render();
        shader->unbind();

        window.update();
    }

    LILA_INFO("Exiting...");
}
