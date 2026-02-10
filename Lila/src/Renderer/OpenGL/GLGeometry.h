#pragma once

#include <vector>

#include "Common/Types.h"

#include "Renderer/Geometry.h"

namespace OpenGL {

    class GLGeometry final : public Lila::Geometry {
    public:
        GLGeometry(const std::vector<f32>& vertices, const std::vector<u32>& indices);
        ~GLGeometry() override;

        void render() override;
        void destroy() override;

    private:
        void create(const std::vector<f32>& vertices, const std::vector<u32>& indices);

    private:
        u32 vao_m, vbo_m, ebo_m;
        i32 vertexCount_m, indexCount_m;
    };

} // namespace OpenGL
