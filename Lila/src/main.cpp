#include <vector>

#include "Rendering/OpenGL/GLGeometry.h"
#include "Rendering/OpenGL/GLShader.h"

#include "Common/Pointers.h"
#include "Logging/Macros.h"
#include "Math/Vec2.h"
#include "Rendering/Window.h"

int main() {
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
