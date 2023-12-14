#pragma once

#include "Lila/utils/Vectors.h"

#include "Shader.h"
#include "Vertex.h"

namespace Lila {

    struct MeshSpecs {
        Lila::Vec3 position = Lila::Vec3(0.0f, 0.0f, 0.0f);
        Lila::Vec3 rotation = Lila::Vec3(0.0f, 0.0f, 0.0f);
        Lila::Vec3 scale    = Lila::Vec3(1.0f, 1.0f, 1.0f);
    };

    class Mesh {
    public:
        Mesh(const char* filepath, MeshSpecs* specs);
        ~Mesh();

        void Render();
        void Delete();

    private:
        void Create();

        MeshSpecs* m_specs;

        Lila::Shader* shader;
        Lila::Vertex* vertex;
    };

}