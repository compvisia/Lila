#include "Mesh.h"

namespace Lila {

    Mesh::Mesh(const char* filepath, MeshSpecs* specs) {
        m_specs = specs;

        #ifdef _WIN32
            shader = new Lila::Shader("assets/shaders/default.vert", "assets/shaders/default.frag");
        #else
            shader = new Lila::Shader("Lila/assets/shaders/default.vert", "Lila/assets/shaders/default.frag");
        #endif

        vertex = new Lila::Vertex();

        Create();
    }

    Mesh::~Mesh() {
        Delete();
    }
    
    void Mesh::Render() {
        shader->Bind();

        shader->setUniform("projection", Lila::Mat4::perspective(16.0f/9.0f, 45.0f, 100.0f, -1.0f));
        shader->setUniform("model", Lila::Mat4::transform(m_specs->position, m_specs->rotation, m_specs->scale));

        vertex->Bind();

        vertex->Render();

        vertex->Unbind();

        shader->Unbind();
    }

    void Mesh::Delete() {
        delete shader;
        delete vertex;
    }

    void Mesh::Create() {
        


    }

}