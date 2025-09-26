#include <vector>

#include "Rendering/OpenGL/GLGeometry.h"
#include "Rendering/OpenGL/GLShader.h"

#include "Common/Pointers.h"
#include "Common/Types.h"
#include "Logging/Macros.h"
#include "Math/Vec2.h"
#include "Rendering/Window.h"

#include "ECS/Entity.h"
#include "ECS/EntityManager.h"
#include "ECS/Components.h"
#include "ECS/ComponentManager.h"

struct Transform {
    f32 x, y, z;
};

struct Tag {
    u64 tag;
};

int main() {
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
    Unique<Lila::Window> window = unique<Lila::Window>("Lila Engine", Vec2i(1280, 720));

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

    std::filesystem::path assetPath = Lila::getProjectPath() / "Lila" / "assets";

    Unique<OpenGL::GLGeometry> geometry = unique<OpenGL::GLGeometry>(vertices, indices);
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(assetPath / "default.vert", assetPath / "default.frag");

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
