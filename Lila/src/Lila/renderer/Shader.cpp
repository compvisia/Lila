#include "pch.h"
#include "Shader.h"

#include "Lila/utils/Mat4.h"

namespace Lila {

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << e.what() << std::endl;
    }

    Create(vertexCode.c_str(), fragmentCode.c_str());
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

void Shader::setUniform(const char* name, int integer) {
    int location = glGetUniformLocation(m_program, name);
    if (location != -1)
        glUniform1i(location, integer);
}

void Shader::Create(const char* vertexSource, const char* fragmentSource) {
    m_program = glCreateProgram();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(m_program, vertexShader);
    glAttachShader(m_program, fragmentShader);

    glLinkProgram(m_program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
}

}