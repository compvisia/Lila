#include <vector>

#include "Rendering/OpenGL/GLGeometry.h"
#include "Rendering/OpenGL/GLShader.h"

#include "Common/Pointers.h"
#include "Common/Types.h"
#include "Logging/Macros.h"

#include "Rendering/Window.h"

#include "ECS/Entity.h"
#include "ECS/EntityManager.h"
#include "ECS/Components.h"
#include "ECS/ComponentManager.h"

#include "Math/Matrix.h"
#include "Math/Quaternion.h"
#include "Math/Vec2.h"
#include "Math/Vec3.h"

#include "Event/EventBus.h"

struct Transform {
    f32 x, y, z;
};

struct Tag {
    u64 tag;
};

struct TemplateEvent {
    u64 test;
};

void eventFunction(const TemplateEvent& event) {
    LILA_DEBUG("Event function called {}", event.test);
};

int main() {
    /*
     * Matrix Example
     */

     Lila::Matrix4f matrix = Lila::Matrix4f::identity();

     LILA_DEBUG("{} {} {} {}", matrix.get(0,0), matrix.get(1,1), matrix.get(2,2), matrix.get(3,3));

    /*
     * Event Example
     */

     // TODO: Define inside an engine system manager.
     Lila::EventBus bus;

     /* <-- README -->
      * Lila::EventBus::subscribe returns a EventSubscription object.
      * The return value MUST be captured using a variable.
      * You can use this variable to manually disconnect the subscription.
      * Or forget about it and automatically disconnect it when it goes out of scope.
      */
     auto sub = bus.subscribe<TemplateEvent>(eventFunction);

     bus.emit(TemplateEvent{1234567890});

     // sub.disconnect();

    /*
     * Quaternion Example
     */

     Lila::Quaternionf q = Lila::Quaternionf::fromEuler(0.0f, 0.0f, 0.0f);
     Lila::Vec3f euler = q.toEuler();
     LILA_DEBUG("{} {} {}", euler.x, euler.y, euler.z);

     f32 dot = q.dot(Lila::Quaternionf::identity());
     LILA_DEBUG("Dot product: {}", dot);


     Lila::Quaternionf q90 = Lila::Quaternionf::fromEuler(0.0f, 3.1415926535f / 2.0f, 0.0f);
     Lila::Vec3f euler90 = q90.toEuler();
     LILA_DEBUG("{} {} {}", euler90.x, euler90.y, euler90.z);

     f32 dot90 = q90.dot(Lila::Quaternionf::identity());
     LILA_DEBUG("Dot product: {}", dot90);


     // Multiplication oders
     Lila::Quaternionf q1 = Lila::Quaternionf(1, 1, 0, 0);
     Lila::Quaternionf q2 = Lila::Quaternionf(1, 0, 1, 1);

     Lila::Quaternionf a = q1 * q2;
     Lila::Quaternionf b = q2 * q1;

     LILA_DEBUG("q1 * q2 = {} {} {} {}", a.w, a.x, a.y, a.z);
     LILA_DEBUG("q2 * q1 = {} {} {} {}", b.w, b.x, b.y, b.z);

     b8 check = a != b;
     LILA_DEBUG("Quaternion multiplication order check: {}", check);

     LILA_DEBUG("Quaternion norm / magnitude check: {}", a.magnitude());

     Lila::Quaternionf p = Lila::Quaternionf(0.333f, 0.666f, 0, 0);
     Lila::Quaternionf pq = p.inverse();

     Lila::Quaternionf c = p * pq;
     Lila::Quaternionf d = pq * p;

     LILA_DEBUG("p * p^-1 = {} {} {} {}", c.w, c.x, c.y, c.z);
     LILA_DEBUG("p^-1 * p = {} {} {} {}", d.w, d.x, d.y, d.z);

    /*
     * ECS Example
     */
    Lila::ECS::EntityManager em;
    Lila::ECS::ComponentManager cm;

    cm.registerComponent<Transform>();
    cm.registerComponent<Tag>();

    Lila::ECS::Entity player = em.createEntity();
    Lila::ECS::Entity enemy = em.createEntity();

    cm.addComponent(player, Transform{0.0f, 0.0f, 0.0f});
    cm.addComponent(player, Tag{5734});

    cm.addComponent(enemy, Transform{5.0f, 0.0f, 0.0f});

    Lila::ECS::ComponentSignature sigPlayer;
    sigPlayer.set(0);
    sigPlayer.set(1);
    em.setSignature(player, sigPlayer);

    Lila::ECS::ComponentSignature sigEnemy;
    sigEnemy.set(0);
    em.setSignature(enemy, sigEnemy);

    auto systemFunction = [&cm, &em]() {
        for(Lila::ECS::Entity e : em.getAliveEntities()) {
            auto sig = em.getSignature(e);
            if(sig.test(0)) {
                auto& t = cm.getComponent<Transform>(e);

                LILA_DEBUG("{}, {}, {}", t.x, t.y, t.z)
            }
            if(sig.test(1)) {
                auto& tag = cm.getComponent<Tag>(e);
                LILA_DEBUG("{}", tag.tag)
            }
        }
    };

    systemFunction();

    /*
     * Render Example
     */
    Unique<Lila::Window> window = unique<Lila::Window>("Lila Engine", Lila::Vec2i(1280, 720));

    std::vector<f32> vertices {
         1,  1, -1,   1, 1,
         1, -1, -1,   1, 0,
        -1, -1, -1,   0, 0,
        -1,  1, -1,   0, 1
    };
    std::vector<u32> indices {
        0, 1, 3,
        1, 2, 3
    };

    Unique<OpenGL::GLGeometry> geometry = unique<OpenGL::GLGeometry>(vertices, indices);
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(Lila::ASSET_PATH / "default.vert", Lila::ASSET_PATH / "default.frag");

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window->getHandle())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

        shader->bind();
        geometry->render();
        shader->unbind();

        window->update();
    }

    LILA_INFO("Exiting...");
}
