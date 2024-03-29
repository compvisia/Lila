#include "Vertex.h"

namespace Lila {

    Vertex::Vertex(std::vector<float> vertices, std::vector<unsigned int> indices) {
        this->vertices = vertices;
        this->indices  = indices;

        Create();
    }

    Vertex::~Vertex() {
        Delete();
    }

    void Vertex::Bind() {
        glBindVertexArray(vao);
    }

    void Vertex::Render() {
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void Vertex::Unbind() {
        glBindVertexArray(0);
    }

    void Vertex::Delete() {
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);

        glDeleteVertexArrays(1, &vao);
    }


    void Vertex::Create() {

        // 3D Cube
        /*std::vector<float> vertices = {
            -1, -1,  1,     0, 0, // 0
             1, -1,  1,     1, 0, // 1
            -1,  1,  1,     0, 1, // 2
             1,  1,  1,     1, 1, // 3
            -1, -1, -1,     0, 0, // 4
             1, -1, -1,     1, 0, // 5
            -1,  1, -1,     0, 1, // 6
             1,  1, -1,     1, 1, // 7
        };

        std::vector<unsigned int> indices = {
            2, 6, 7,
            2, 3, 7,

            0, 4, 5,
            0, 1, 5,

            0, 2, 6,
            0, 4, 6,

            1, 3, 7,
            1, 5, 7,

            0, 2, 3,
            0, 1, 3,

            4, 6, 7,
            4, 5, 7
        };*/

        // 2D Plane
        /*std::vector<float> vertices = {
            1, 1, 0,   1, 1, // 0
            1, 0, 0,   1, 0, // 1
            0, 0, 0,   0, 0, // 2
            0, 1, 0,   0, 1, // 3
        };

        std::vector<unsigned int> indices = {
            0, 1, 2,
            2, 3, 0
        };*/

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}