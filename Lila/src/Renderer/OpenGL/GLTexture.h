#pragma once

#include <filesystem>

#include "Renderer/Texture.h"

#include "Common/Types.h"

namespace OpenGL {

    class GLTexture final : public Lila::Texture {
    public:
        GLTexture();
        GLTexture(const std::filesystem::path &path);
        ~GLTexture() override;

        void bind() override;
        void unbind() override;

        void destroy() override;

    private:
        void create();

    private:
        std::filesystem::path path_m = "";
        u32 id_m = 0;
        i32 width_m = 0;
        i32 height_m = 0;
        i32 channels_m = 0;
    };

} // namespace OpenGL
