#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "core/Window.h"

#include "renderer/OpenGL/GLGeometry.h"
#include "renderer/OpenGL/GLShader.h"

#include "platform/filesystem.h"

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