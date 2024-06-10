#include "GLShader.h"

#include "Lila/Core/Logger.h"

#include "Lila/Utils/FileUtils.h"

namespace OpenGL {

    GLShader::GLShader(std::string vertexPath, std::string fragmentPath) {
        create(vertexPath, fragmentPath);
    }

    GLShader::~GLShader() {
        
    }

    void GLShader::bind() {    
    #ifdef LILA_OPENGL_CONTEXT
        glUseProgram(program_m);
    #endif
    }

    void GLShader::unbind() {
    #ifdef LILA_OPENGL_CONTEXT
        glUseProgram(0);
    #endif
    }

    void GLShader::create(std::string vertexPath, std::string fragmentPath) {
    #ifdef LILA_OPENGL_CONTEXT
        std::string vertexContents = Lila::getContents(vertexPath);
		std::string fragmentContents = Lila::getContents(fragmentPath);

		const char* vert = vertexContents.c_str();
		const char* frag = fragmentContents.c_str();

		program_m = glCreateProgram();

		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertex, 1, &vert, 0);
		glShaderSource(fragment, 1, &frag, 0);

		glCompileShader(vertex);

		int success;
		char infoLog[512];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			lila_error("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s", infoLog);
		}

		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			lila_error("ERROR::SHADER::FRAG::COMPILATION_FAILED %s", infoLog);
		}

		glAttachShader(program_m, vertex);
		glAttachShader(program_m, fragment);

		glLinkProgram(program_m);

		glGetProgramiv(program_m, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(program_m, 512, NULL, infoLog);
            lila_error("ERROR::SHADER::PROGRAM::LINKING_FAILED %s", infoLog);
		}

		glDeleteShader(vertex);
		glDeleteShader(fragment);
    #endif
	}

    void GLShader::destroy() {
    #ifdef LILA_OPENGL_CONTEXT
        glDeleteProgram(program_m);
    #endif
    }

} // namespace OpenGL