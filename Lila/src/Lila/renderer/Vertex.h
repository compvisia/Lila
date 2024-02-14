#pragma once

#include "glad/glad.h"

#include <vector>

namespace Lila {

    class Vertex {
    public:
        Vertex(std::vector<float> vertices, std::vector<unsigned int> indices);
        ~Vertex();

        void Bind();
        void Render();
        void Unbind();
        void Delete();

    private:
        void Create();

        unsigned int vao, vbo, ebo;

        std::vector<float> vertices;
        std::vector<unsigned int> indices;
    };

}