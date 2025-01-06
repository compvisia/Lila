#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "core/Window.h"

#include "renderer/OpenGL/GLGeometry.h"
#include "renderer/OpenGL/GLShader.h"
#include "renderer/OpenGL/GLTexture.h"

#include "math/math.h"

#include "math/matrix4.h"

#include "platform/filesystem.h"

#include "ecs/Registry.h"

#include "renderer/Perspective.h"

#include "math/vec2.h"
#include "math/vec3.h"
#include "math/vec4.h"

struct Transform {
    u64 x = 0, y = 0, z = 0;
};

int main(int argc, char** argv) {    
    LOG_INFO("Successfully Booted up!");

    Unique<Lila::Window> window = unique<Lila::Window>("Lila", 1280, 720);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERROR("GLAD failed to initialize!");
        return 0;
	}

    LOG_INFO("OpenGL version %s", glGetString(GL_VERSION));

    vec<f32> vertices {
         1,  1, -1,   1, 1,
         1, -1, -1,   1, 0,
        -1, -1, -1,   0, 0,
        -1,  1, -1,   0, 1  
    };
    vec<u32> indices {
        0, 1, 3,
        1, 2, 3
    };

    std::filesystem::path assetPath = Lila::getProjectPath() / "Lila" / "assets";

    Unique<OpenGL::GLGeometry> geometry = unique<OpenGL::GLGeometry>(vertices, indices);
    Unique<OpenGL::GLShader> shader = unique<OpenGL::GLShader>(assetPath / "texture.vert", assetPath / "texture.frag");
    Unique<OpenGL::GLTexture> texture = unique<OpenGL::GLTexture>(assetPath / "texture.png");
    
    Lila::Registry registry;

    u64 entity = registry.create();

    // Lila::ComponentMask mask;
    // registry.setMask(entity, mask);

    registry.registerComponent<Transform>();

    Shared<Transform> transform = registry.addComponent<Transform>(entity);

    transform->x = 10;

    Shared<Transform> transform2 = registry.getComponent<Transform>(entity);
    LOG_DEBUG("%d", transform2->x);

    glEnable(GL_DEPTH_TEST);
    while(!glfwWindowShouldClose(window->getPointer())) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);

        texture->bind();
        shader->bind();
        geometry->render();
        shader->unbind();
        texture->unbind();

        glfwSwapBuffers(window->getPointer());
        glfwPollEvents();
    }

    texture->destroy();
    shader->destroy();
    geometry->destroy();

    window->destroy();

    return 0;
}
