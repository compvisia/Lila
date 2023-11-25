#pragma once

#include "Lila/utils/Mat4.h"

#include "glad/glad.h"

namespace Lila {

class Shader {
public:
    Shader();
    ~Shader();

    void Bind();
    void Unbind();
    void Delete();

    void setUniform(const char* name, Mat4 matrix);

private:
    void Create();

    unsigned int m_program;

    std::string vertexSource;
    std::string fragmentSource;
};

}