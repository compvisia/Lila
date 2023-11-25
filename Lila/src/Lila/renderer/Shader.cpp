#include "pch.h"
#include "Shader.h"

#include "Lila/utils/Mat4.h"

namespace Lila {

Shader::Shader() {
    Create();
}

Shader::~Shader() {
    Delete();
}

void Shader::Bind()   { glUseProgram(m_program); }
void Shader::Unbind() { glUseProgram(0); }

void Shader::Delete() {
    glDeleteProgram(m_program);
}

void Shader::setUniform(const char* name, Mat4 matrix) {
    int location = glGetUniformLocation(m_program, name);
    if (location != -1)
        glUniformMatrix4fv(location, 1, GL_FALSE, matrix.getAll());
}

void Shader::Create() {
    m_program = glCreateProgram();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vertexChar = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec3 position;\n"
        "\n"
        "uniform mat4 projection;\n"
        "uniform mat4 model;\n"
        "\n"
        "out vec4 color;\n"
        "\n"
        "void main() {\n"
        "   gl_Position = projection * model * vec4(position, 1.0);\n"
        "   color = vec4(position.x, position.y, position.z, 1.0);\n"
        "}\n\0";

    const char* fragmentChar = 
        "#version 330 core\n"
        "\n"
        "out vec4 FragColor;\n"
        "\n"
        "in vec4 color;\n"
        "\n"
        "void main() {\n"
        "    FragColor = color;\n"
        "}\n\0";

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(m_program, vertexShader);
    glAttachShader(m_program, fragmentShader);

    glLinkProgram(m_program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
}

}