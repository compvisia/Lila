#include "GLGeometry.h"

#include <glad/glad.h>

namespace OpenGL {

    GLGeometry::GLGeometry(const std::vector<f32>& vertices, const std::vector<u32>& indices) {
        vertexCount_m = vertices.size();
        indexCount_m = indices.size();

        create(vertices, indices);
    }

    GLGeometry::~GLGeometry() {
        GLGeometry::destroy();
    }

    void GLGeometry::render() {
        glBindVertexArray(vao_m);

        glDrawElements(GL_TRIANGLES, indexCount_m, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
    }

    void GLGeometry::destroy() {
        glDeleteBuffers(1, &vbo_m);
        glDeleteBuffers(1, &ebo_m);

        glDeleteVertexArrays(1, &vao_m);
    }

    void GLGeometry::create(const std::vector<f32>& vertices, const std::vector<u32>& indices) {
        glGenVertexArrays(1, &vao_m);

        glGenBuffers(1, &vbo_m);
        glGenBuffers(1, &ebo_m);

        glBindVertexArray(vao_m);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_m);
        glBufferData(GL_ARRAY_BUFFER, vertexCount_m * sizeof(f32), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_m);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount_m * sizeof(u32), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), static_cast<void *>(nullptr));
    	glEnableVertexAttribArray(0);
        // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(3 * sizeof(f32)));
    	// glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // namespace OpenGL
