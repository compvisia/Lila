#include "GLShader.h"

#include <glad/glad.h>

#include <vector>

#include "math/matrix4.h"
#include "math/math.h"

namespace OpenGL {

GLShader::GLShader(std::filesystem::path vertexPath, std::filesystem::path fragmentPath) {
    vertexPath_m = vertexPath;
    fragmentPath_m = fragmentPath;

    create();
}

GLShader::~GLShader() {}

void GLShader::bind() {
    glUseProgram(program_m);

    i32 location = glGetUniformLocation(program_m, "proj");
    Lila::Matrix4 proj;
    proj.perspective(60.0f, 16.0f/9.0f, 0.1f, 20.0f);
    glUniformMatrix4fv(location, 1, false, proj.getEntries().data());
}

void GLShader::unbind() {
    glUseProgram(0);
}

void GLShader::destroy() {
    glDeleteProgram(program_m);
}

void GLShader::create() {
    program_m = glCreateProgram();

    str vertexShader = Lila::getContentsByPath(vertexPath_m), fragmentShader = Lila::getContentsByPath(fragmentPath_m);

    u32 vso = glCreateShader(GL_VERTEX_SHADER);
    u32 fso = glCreateShader(GL_FRAGMENT_SHADER);

    if(!createShader(vso, vertexShader))
        destroy();
    
    if(!createShader(fso, fragmentShader))
        destroy();

    if(!createProgram(vso, fso))
        destroy();
    
    glDeleteShader(vso);
    glDeleteShader(fso);
}

b8 GLShader::createShader(u32& shaderObject, str& shaderContents) {
    const char* contentsPointer = shaderContents.c_str();
    glShaderSource(shaderObject, 1, &contentsPointer, 0);

    i32 success = 0;

    glCompileShader(shaderObject);
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);

    if(!success) {
        i32 maxLength = 128;
        std::vector<c8> errorLog(maxLength+1);
        glGetShaderInfoLog(shaderObject, maxLength, &maxLength, &errorLog[0]); 
        str error(begin(errorLog), end(errorLog));
        LOG_ERROR("Shader could not compile: %s", error.c_str());

        return false;
    }

    return true;
}

b8 GLShader::createProgram(u32& vso, u32& fso) {
    glAttachShader(program_m, vso);
    glAttachShader(program_m, fso);

    i32 success = 0;

    glLinkProgram(program_m);
    glGetProgramiv(program_m, GL_LINK_STATUS, &success);

    if(!success) {
        i32 maxLength = 128;
        std::vector<c8> errorLog(maxLength+1);
        glGetProgramInfoLog(program_m, maxLength, &maxLength, &errorLog[0]); 
        str error(begin(errorLog), end(errorLog));
        LOG_ERROR("Program could not link: %s", error.c_str());

        return false;
    }

    return true;
}

} // namespace OpenGL