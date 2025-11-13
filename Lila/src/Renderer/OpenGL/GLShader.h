#pragma once

#include <string>

#include <glm/mat4x4.hpp>

#include "Common/Types.h"
#include "Common/Filesystem.h"
#include "Renderer/Shader.h"

namespace OpenGL {

    class GLShader final : public Lila::Shader {
    public:
        GLShader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
        ~GLShader() override;

        void bind() override;
        void unbind() override;

        void destroy() override;

        void uniformMatrix(const std::string& name, const glm::mat4& matrix) const;

    private:
        void create();

        static b8 createShader(const u32& shaderObject, const std::string& shaderContents);
        [[nodiscard]] b8 createProgram(const u32& vso, const u32& fso) const;

    private:
        std::filesystem::path vertexPath_m, fragmentPath_m;
        u32 program_m{};
    };

} // namespace OpenGL
