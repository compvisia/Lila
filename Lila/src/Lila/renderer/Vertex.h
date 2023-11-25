#pragma once

#include "glad/glad.h"

namespace Lila {

class Vertex {
public:
    Vertex();
    ~Vertex();

    void Bind();
    void Render();
    void Unbind();
    void Delete();

private:
    void Create();

    unsigned int vao, vbo, ebo;
};

}