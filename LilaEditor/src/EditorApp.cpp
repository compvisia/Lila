#include "Lila/Lila.h"
#include "Lila/core/Entry.h"

#include "Lila/ecs/Registry.h"

#include "Editor/Editor.h"

class EditorApp : public Lila::Application {
public:
    EditorApp() { name = "Editor"; };

    ~EditorApp() {}

    void run() override {
        // ECS
        Lila::Registry registry;

        registry.registerComponent<Lila::Tag>();
        registry.registerComponent<Lila::Transform>();

        Lila::Entity entity = registry.createEntity();

        registry.assign<Lila::Transform>(entity, Lila::Transform{});

        Lila::Transform& transform = registry.getComponent<Lila::Transform>(entity);
        transform.position = 10;

        Lila::Transform& t = registry.getComponent<Lila::Transform>(entity);
        //info("Entity %d", t.position);

        // Window
        Lila::Window* window = new Lila::Window("Editor", 1280, 720);
        //glfwSetInputMode(window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED); 


        /*// Input
        Lila::Keyboard keyboard;
        Lila::Mouse mouse;

        keyboard.setCallback(window);
        mouse.setCallback(window);

        Lila::Camera camera(keyboard, mouse);

        Lila::Renderer renderer;


        // Imgui
        Editor::Editor editor(window, registry);

        glEnable(GL_DEPTH_TEST);
        while (!window->windowClose()) {
            if(keyboard.isKeyDown(GLFW_KEY_ESCAPE))
                glfwSetWindowShouldClose(window->getWindow(), GLFW_TRUE);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.1f, 0.3f, 0.4f, 1.0f);

            renderer.renderQueue();

            editor.update();
            editor.onImGui();

            camera.update();

            window->Update();
        }*/

        delete window;
    }

};

Lila::Application* Lila::CreateApp() {
    return new EditorApp();
}