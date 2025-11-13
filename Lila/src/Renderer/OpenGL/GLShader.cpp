#include "GLShader.h"

#include <glad/glad.h>

namespace OpenGL {

    GLShader::GLShader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) {
        vertexPath_m = vertexPath;
        fragmentPath_m = fragmentPath;

        create();
    }

    GLShader::~GLShader() {
        GLShader::destroy();
    }

    void GLShader::bind() {
        glUseProgram(program_m);
    }

    void GLShader::unbind() {
        glUseProgram(0);
    }

    void GLShader::destroy() {
        glUseProgram(0);
        glDeleteProgram(program_m);
    }

    void GLShader::uniformMatrix(const std::string& name, const glm::mat4& matrix) const {
        i32 location = glGetUniformLocation(program_m, name.c_str());
        glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
    }

    void GLShader::create() {
        program_m = glCreateProgram();

        std::string vertexShader = Lila::getContentsByPath(vertexPath_m);
        std::string fragmentShader = Lila::getContentsByPath(fragmentPath_m);

        u32 vso = glCreateShader(GL_VERTEX_SHADER);
        u32 fso = glCreateShader(GL_FRAGMENT_SHADER);

        if(!createShader(vso, vertexShader)) {
            destroy();
            return;
        }


        if(!createShader(fso, fragmentShader)) {
            destroy();
            return;
        }


        if(!createProgram(vso, fso)) {
            destroy();
            return;
        }

        glDeleteShader(vso);
        glDeleteShader(fso);
    }

    b8 GLShader::createShader(const u32& shaderObject, const std::string& shaderContents) {
        const char* contentsPointer = shaderContents.c_str();
        glShaderSource(shaderObject, 1, &contentsPointer, nullptr);

        i32 success = 0;

        glCompileShader(shaderObject);
        glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);

        if(!success) {
            i32 maxLength = 128;
            std::vector<c8> errorLog(maxLength+1);
            glGetShaderInfoLog(shaderObject, maxLength, &maxLength, &errorLog[0]);
            std::string error(begin(errorLog), end(errorLog));
            LILA_ERROR("Shader could not compile: {}", error.c_str());

            return false;
        }

        return true;
    }

    b8 GLShader::createProgram(const u32& vso, const u32& fso) const {
        glAttachShader(program_m, vso);
        glAttachShader(program_m, fso);

        i32 success = 0;

        glLinkProgram(program_m);
        glGetProgramiv(program_m, GL_LINK_STATUS, &success);

        if(!success) {
            i32 maxLength = 128;
            std::vector<c8> errorLog(maxLength+1);
            glGetProgramInfoLog(program_m, maxLength, &maxLength, &errorLog[0]);
            std::string error(begin(errorLog), end(errorLog));
            LILA_ERROR("Program could not link: {}", error.c_str());

            return false;
        }

        return true;
    }

} // namespace OpenGL
