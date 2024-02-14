#include "Mesh.h"

#include <fstream>
#include <string>
#include <iostream>

namespace Lila {

    Mesh::Mesh(const char* filepath) {
        this->filepath = filepath;
        Create();
    }

    Mesh::~Mesh() {
        Delete();
    }
    
    void Mesh::Render() {
        shader->Bind();

        shader->setUniform("mTexture", 0);

        shader->setUniform("projection", Lila::Mat4::perspective(16.0f / 9.0f, 45.0f, 100.0f, -1.0f));
        shader->setUniform("cam", Lila::Mat4::identity());
        shader->setUniform("model", Lila::Mat4::transform(position, rotation, scale));

        vertex->Bind();

        vertex->Render();

        vertex->Unbind();

        shader->Unbind();
    }

    void Mesh::Render(Camera camera) {
        shader->Bind();

        shader->setUniform("mTexture", 0);

        shader->setUniform("projection", Lila::Mat4::perspective(16.0f/9.0f, 45.0f, 100.0f, -1.0f));
        shader->setUniform("cam", Lila::Mat4::multiply(
            Mat4::translate(camera.position.X(), camera.position.Y(), camera.position.Z()),
            Mat4::rotate(camera.rotation.X(), camera.rotation.Y(), camera.rotation.Z())));
        shader->setUniform("model", Lila::Mat4::transform(position, rotation, scale));

        vertex->Bind();

        vertex->Render();

        vertex->Unbind();

        shader->Unbind();
    }

    void Mesh::Delete() {
        delete shader;
        delete vertex;
    }

    void Mesh::Create() {
        MeshLoader meshLoader(filepath);

        // TODO: Create an asset that stores default shaders
        #ifdef _WIN32
            shader = new Lila::Shader("assets/shaders/default.vert", "assets/shaders/default.frag");
        #else
            shader = new Lila::Shader("LilaEditor/assets/shaders/default.vert", "LilaEditor/assets/shaders/default.frag");
        #endif

        vertex = new Lila::Vertex(meshLoader.vertices, meshLoader.indices);
    }

    // 
    // Mesh Loader
    //

    MeshLoader::MeshLoader(const char* filepath) {
        readFileObj(filepath);
    }

    void MeshLoader::readFileObj(const char* filepath) {
        std::ifstream model(filepath);

        if (!model.is_open()) return;

        std::string line;
        while (getline(model, line)) {
            if(line[0] == 'v') {
                if (line[1] == ' ') {
                    float x, y, z;
                    sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);

                    vertices.push_back(x);
                    vertices.push_back(y);
                    vertices.push_back(z);

                    vertices.push_back(x);
                    vertices.push_back(-y);
                }
                else continue;
            }
            if(line[0] == 'f') {
                unsigned int x, y, z;
                sscanf(line.c_str(), "f %d %d %d", &x, &y, &z);

                indices.push_back(x-1);
                indices.push_back(y-1);
                indices.push_back(z-1);
            }
        }
        
    }

}