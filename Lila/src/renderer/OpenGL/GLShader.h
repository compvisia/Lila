#pragma once

#include "GLTypes.h"

#include "platform/filesystem.h"

#include "renderer/Shader.h"

namespace OpenGL {

class GLShader : public Lila::Shader {
public:
    GLShader(std::filesystem::path vertexPath, std::filesystem::path fragmentPath);
    ~GLShader();

    void bind() override;
    void unbind() override;

    void destroy() override;

private:
    void create();

    b8 createShader(u32& shaderObject, str& shaderContents);
    b8 createProgram(u32& vso, u32& fso);

private:
    std::filesystem::path vertexPath_m, fragmentPath_m;
    u32 program_m;
};

} // namespace OpenGL