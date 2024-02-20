#include "Lila/Lila.h"

#include "Lila/ecs/World.h"

#include "Editor/Editor.h"

int main(void) {
    // ECS
    Lila::World* world = new Lila::World();

    Lila::Entity entity = world->createNew();

    printf("%s\n", world->getComponent<Lila::Tag>(entity)->name);


    // Window
    Lila::Window* window = new Lila::Window("Editor", 1280, 720);
    //glfwSetInputMode(window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // Input
    Lila::Keyboard keyboard;
    Lila::Mouse mouse;

    keyboard.setCallback(window);
    mouse.setCallback(window);

    Lila::Camera camera(keyboard, mouse);
    
    Lila::Renderer renderer;


    // Imgui
    Editor::Editor editor(window, world);
    

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
    }

    delete world;

    delete window;

    return 0;
}