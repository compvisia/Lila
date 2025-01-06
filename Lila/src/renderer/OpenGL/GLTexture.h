#pragma once

#include "GLTypes.h"

#include "platform/filesystem.h"

#include "renderer/Texture.h"

namespace OpenGL {

class GLTexture : public Lila::Texture {
public:
    GLTexture(std::filesystem::path texturePath);
    ~GLTexture();

    void bind() override;
    void unbind() override;

    void destroy() override;

private:
    void create();

private:
    std::filesystem::path texturePath_m;
    u32 textureId_m;
    i32 width_m, height_m, channels_m;
};

} // namespace OpenGL