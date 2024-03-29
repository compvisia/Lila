#pragma once

#include "Lila/utils/Vectors.h"

#include "Lila/world/Camera.h"

#include "Shader.h"
#include "Vertex.h"

namespace Lila {

    class Mesh {
    public:
        Mesh(const char* filepath);
        ~Mesh();

        void Render();
        void Render(Camera camera);

        void Delete();

        Lila::Vec3 position = Lila::Vec3(0.0f, 0.0f, 0.0f);
        Lila::Vec3 rotation = Lila::Vec3(0.0f, 0.0f, 0.0f);
        Lila::Vec3 scale = Lila::Vec3(1.0f, 1.0f, 1.0f);

    private:
        void Create();

        const char* filepath;

        Lila::Shader* shader;
        Lila::Vertex* vertex;
    };


    class MeshLoader {
    public:
        MeshLoader(const char* filepath);

        std::vector<float> vertices;
        std::vector<unsigned int> indices;

    private:
        void readFileObj(const char* filepath);
    };

}