#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "core/Window.h"

#include "renderer/OpenGL/GLGeometry.h"
#include "renderer/OpenGL/GLShader.h"

#include "platform/filesystem.h"

#include "ecs/Registry.h"

struct Transform {
    u64 x = 0, y = 0, z = 0;
};

int main(int argc, char** argv) {    
    LOG_INFO("Successfully Booted up!");

    Unique<Lila::Window> window = unique<Lila::Window>("Lila", 1280, 720);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERROR("GLAD Failed!");
        return 0;
	}

    LOG_INFO("OpenGL version %s", glGetString(GL_VERSION));

    f32 vertices[] = {
        -1, -1,  1,
         1, -1,  1,
        -1,  1,  1,
         1,  1,  1,
        -1, -1, -1,
         1, -1, -1,
        -1,  1, -1,
         1,  1, -1
    };

    u32 indices[] = {
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

    std::filesystem::path shaderPath = Lila::getProjectPath() / "Lila" / "assets";

    Unique<OpenGL::GLGeometry> geometry = unique<OpenGL::GLGeometry>(vertices, indices, 24, 36);
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(shaderPath / "default.vert", shaderPath / "default.frag");
    
    Lila::Registry registry;

    u64 entity = registry.create();

    Lila::ComponentMask mask;
    registry.setMask(entity, mask);

    registry.registerComponent<Transform>();

    Shared<Transform> transform = registry.addComponent<Transform>(entity);

    transform->x = 10;

    Shared<Transform> transform2 = registry.getComponent<Transform>(entity);

    LOG_DEBUG("%d", transform2->x);

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window->getPointer())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

        shader->bind();
        geometry->render();
        shader->unbind();

        glfwSwapBuffers(window->getPointer());
        glfwPollEvents();
    }

    geometry->destroy();
    shader->destroy();
    
    window->destroy();

    return 0;
}