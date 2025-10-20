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

#include "Math/Matrix.h"
#include "Math/Quaternion.h"
#include "Math/Vec2.h"
#include "Math/Vec3.h"

#include "Event/EventBus.h"

#include "Input/Keyboard.h"

struct Transform {
    f32 x, y, z;
};

struct Tag {
    u64 tag;
};

void keyEventFunction(Lila::KeyEvent event) {
    LILA_DEBUG("Key {}, Action {}", event.key, event.action);
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

    /*
     * Matrix Example
     */

     Lila::Matrix4f matrix = Lila::Matrix4f::identity();

     LILA_DEBUG("{} {} {} {}", matrix.get(0,0), matrix.get(1,1), matrix.get(2,2), matrix.get(3,3));

    /*
     * Quaternion Example
     */

     Lila::Quaternionf q = Lila::Quaternionf::fromEuler(0.0f, 0.0f, 0.0f);
     Lila::Vec3f euler = q.toEuler();
     LILA_DEBUG("{} {} {}", euler.x, euler.y, euler.z);

     f32 dot = q.dot(Lila::Quaternionf::identity());
     LILA_DEBUG("Dot product: {}", dot);


     Lila::Quaterniond q90 = Lila::Quaterniond::fromEuler(0.0f, 3.1415926535f / 2.0f, 0.0f);
     LILA_DEBUG("{} {} {} {}", q90.w, q90.x, q90.y, q90.z);
     Lila::Vec3d euler90 = q90.toEuler();
     LILA_DEBUG("{} {} {}", euler90.x, euler90.y, euler90.z);

     f64 dot90 = q90.dot(Lila::Quaterniond::identity());
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

     LILA_DEBUG("Quaternion norm / magnitude check: {}", a.norm());

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

    Lila::WindowSpecs windowSpecs;

    Lila::Window window = Lila::Window(windowSpecs);

    // TODO: Define inside an engine system manager.
    Lila::EventBus bus;

    /* <-- IMPORTANT -->
     * Lila::EventBus::subscribe returns a EventSubscription object.
     * This EventSubscription object MUST be captured by using a variable, else the subscription is invalidated.
     * When it goes out of scope the subscription object will automatically disconnect.
     */
    auto sub = bus.subscribe<Lila::KeyEvent>(keyEventFunction);

    Lila::setCallback(window, &bus);

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
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(Lila::getAssetPath() / "default.vert", Lila::getAssetPath() / "default.frag");

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window.getHandle())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

        shader->bind();
        geometry->render();
        shader->unbind();

        window.update();
    }

    LILA_INFO("Exiting...");
}
