#pragma once

#include "GLSuccess.h"

#include "Lila/Rendering/Shader.h"

#include "Platform/Defines.h"
#include "Platform/Graphics.h"

#include <string>

namespace OpenGL {

    class GLShader : public Lila::Shader {
    public:
        GLShader(std::string vertexPath, std::string fragmentPath);
        ~GLShader();

        void bind() override;
		void unbind() override;

	protected:
		void create(std::string vertexPath, std::string fragmentPath) override;
		void destroy() override;
    };

} // namespace OpenGL