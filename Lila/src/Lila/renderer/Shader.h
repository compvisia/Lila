#pragma once

#include "Lila/utils/Mat4.h"

#include "glad/glad.h"

namespace Lila {

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Bind();
    void Unbind();
    void Delete();

    void setUniform(const char* name, Mat4 matrix);
    void setUniform(const char* name, int integer);

private:
    void Create(const char* vertexSource, const char* fragmentSource);

    unsigned int m_program;

    std::string vertexSource;
    std::string fragmentSource;
};

}