#include <iostream>

#include "lila/Lila.h"

int main() {

    Lila::Window* Window = new Lila::Window("Lila UI", 1280, 720);
    
    Lila::Vertex* Vertex = new Lila::Vertex();
    Lila::Shader* Shader = new Lila::Shader();

    Lila::Mat4 perspective = Lila::Mat4::perspective(1.77777778f, 45.0f, 100.0f, -1.0f);

    printf("%f\n", perspective.getAll()[0]);

    printf("Hello world!\n");

    glEnable(GL_DEPTH_TEST);

    

    float t = 0;

    while (!Window->windowClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.1f, 0.3f, 0.4f, 1.0f);
        
        Shader->Bind();

        Shader->setUniform("projection", perspective);
        Shader->setUniform("model", Lila::Mat4::transform(0, 0, 5, sin(t)*10.0f, 0, 0, 1, 1, 1));

        Vertex->Bind();

        Vertex->Render();

        Vertex->Unbind();

        Shader->Unbind();

        Window->Update();

        t += 0.0001f;
    }

    delete Shader;
    delete Vertex;

    delete Window;
    
    glfwTerminate();

    return 0;
}