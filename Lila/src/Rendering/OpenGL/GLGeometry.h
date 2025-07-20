#pragma once

#include <vector>

#include "Common/Types.h"

#include "Rendering/Geometry.h"

namespace OpenGL {

    class GLGeometry : public Lila::Geometry {
    public:
        GLGeometry(std::vector<f32> vertices, std::vector<u32> indices);
        ~GLGeometry();

        void render() override;
        void destroy() override;

    private:
        void create(std::vector<f32> vertices, std::vector<u32> indices);

    private:
        u32 vao_m, vbo_m, ebo_m;
        u32 vertexCount_m, indexCount_m;
    };

} // namespace OpenGL
