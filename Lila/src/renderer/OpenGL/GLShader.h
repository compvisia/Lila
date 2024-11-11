#pragma once

#include "platform/filesystem.h"

#include "renderer/Shader.h"

namespace OpenGL {

class GLShader : public Lila::Shader {
public:
    GLShader(str vertexPath, str fragmentPath);
    ~GLShader();

    void bind() override;
    void unbind() override;

    void destroy() override;

private:
    void create();

    b8 createShader(u32& shaderObject, str& shaderContents);
    b8 createProgram(u32& vso, u32& fso);

private:
    str vertexPath_m, fragmentPath_m;
    u32 program_m;
};

} // namespace OpenGL