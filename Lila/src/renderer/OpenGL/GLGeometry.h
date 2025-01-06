#pragma once

#include "GLTypes.h"

#include "renderer/Geometry.h"

namespace OpenGL {

class GLGeometry : public Lila::Geometry {
public:
    GLGeometry(vec<f32> vertices, vec<u32> indices);
    ~GLGeometry();

    void render() override;
    void destroy() override;

private:
    void create(vec<f32> vertices, vec<u32> indices);

private:
    u32 vao_m, vbo_m, ebo_m;
    u32 vertexCount_m, indexCount_m;
};

} // namespace OpenGL