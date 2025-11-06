#include "Application/Application.h"
#include "Renderer/RenderInfo.h"

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
#include "ECS/ComponentManager.h"

#include "Event/EventBus.h"

#include "Input/Keyboard.h"
#include "Input/Mouse.h"

#include "World/Camera.h"

#include <glad/glad.h>

#include "Renderer/Renderer.h"

struct Transform {
    f32 x, y, z;
};

struct Tag {
    u64 tag;
};

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);
f32 cameraSpeed = 0.05;

void keyEventFunction(Lila::KeyEvent event) {
    if(event.key == 65) // A
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(event.key == 68) // D
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    // if(event.key == 340) // Shift
    //     camY -= camSpeed;
    // if(event.key == 32) // Space
    //     camY += camSpeed;

    if(event.key == 87) // W
        cameraPos += cameraSpeed * cameraFront;
    if(event.key == 83) // S
        cameraPos -= cameraSpeed * cameraFront;
}

glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
f64 lastX = 0.0, lastY = 0.0;
f64 yaw = 0.0, pitch = 0.0;
void mousePositionEventFunction(Lila::MousePositionEvent event) {
    f64 mx = event.x - 640;
    f64 my = event.y - 360;
    f64 offsetX = mx - lastX;
    f64 offsetY = my - lastY;
    lastX = mx;
    lastY = my;

    offsetX *= cameraSpeed;
    offsetY *= cameraSpeed;

    yaw += offsetX;
    pitch += offsetY;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
}

int main() {
    Lila::RenderProfile profile;
    profile.renderApi = Lila::RenderApi::OpenGL;
    Lila::Application app(profile);

    auto& window = app.getWindow();

    auto& bus = Lila::createEventBus(app);

    auto& em = Lila::createEntityManager(app);
    auto& cm = Lila::createComponentManager(app);

    LILA_DEBUG("Name: {}", app.getName());
    LILA_DEBUG("Platform: {}", app.getRenderProfile().platform);
    LILA_DEBUG("UUID: {}", static_cast<u64>(app.getUniqueId()));

    glfwSetWindowUserPointer(window.getHandle(), &bus);

    // TODO: Rework the Key Callback so multiple keys can be pressed at once.
    Lila::setKeyCallback(window);

    Lila::setMousePositionCallback(window);

    /* <-- IMPORTANT -->
     * `Lila::EventBus::subscribe` returns a `Lila::EventSubscription` object.
     * The event subscription object **MUST** be captured using a variable, else the subscription is invalid.
     * When it goes out of scope the subscription object will automatically disconnect.
     * You can also manually disconnect using the `disconnect()` method.
     */
    auto subKeyEvent = bus.subscribe<Lila::KeyEvent>(keyEventFunction);
    auto subMousePos = bus.subscribe<Lila::MousePositionEvent>(mousePositionEventFunction);

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

    /*
     * ECS Example
     */

    cm.registerComponent<Lila::CameraComponent>();

    const Lila::ECS::Entity camera = em.createEntity();
    cm.addComponent(camera, Lila::CameraComponent{});

    cm.registerComponent<Lila::Testing::MeshComponent>();

    const Lila::ECS::Entity entity = em.createEntity();
    cm.addComponent(entity, Lila::Testing::MeshComponent{
        vertices,
        indices,
        Lila::getAssetPath() / "default.vert",
        Lila::getAssetPath() / "default.frag"
    });

    Lila::Testing::registerForRendering(app, entity);

    glEnable(GL_DEPTH_TEST);
    while(window.isRunning()) {
        window.update();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

		Lila::Testing::render();
    }

    LILA_INFO("Exiting...");
}
