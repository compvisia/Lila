#pragma once

#include "renderer/Geometry.h"

namespace OpenGL {

class GLGeometry : public Lila::Geometry {
public:
    GLGeometry(const f32 vertices[], const u32 indices[], const u32 vertexCount, const u32 indexCount);
    ~GLGeometry();

    void render() override;
    void destroy() override;

private:
    void create(const f32 vertices[], const u32 indices[]);

private:
    u32 vao_m, vbo_m, ebo_m;
    u32 vertexCount_m, indexCount_m;
};

} // namespace OpenGL