#pragma once

#include <filesystem>
#include <vector>

#include "Application/Application.h"

#include "ECS/ComponentManager.h"

#include "Common/Pointers.h"

#include "OpenGL/GLGeometry.h"
#include "OpenGL/GLShader.h"

#include "Log/Macros.h"

namespace Lila::Testing {

    static std::unordered_map<ECS::Entity, Unique<Geometry>> geometryMap_S{};
    static std::unordered_map<ECS::Entity, Unique<Shader>> shaderMap_S{};

    /*
     * This component will be used to render meshes using ECS.
     * A system will be made to render the mesh reference object with the shader object reference.
     *
     * The mesh object will contain:
     * - Mesh type (Only position, position + normal, etc.)
     * - The reference to the actual mesh data object
     *
     * The shader object will contain:
     * - Shader type (Vertex, Fragment, etc.)
     * - Extension of the shader (.glsl, .hlsl, .spir-v)
     * - The reference to the actual shader data object
     *
     * The material object will contain:
     * - Material type (Basic, Phong, etc.)
     * - Material data.
     */
    // TODO: Change raw data to asset object reference
    struct MeshComponent {
        std::vector<f32> vertices;
        std::vector<u32> indices;
        std::filesystem::path vertexPath;
        std::filesystem::path fragmentPath;
    };

    inline void registerForRendering(const Application& app, const ECS::Entity entity) {
        RenderProfile profile = app.getRenderProfile();

        if(profile.renderApi == RenderApi::None) {
            LILA_WARN("registerForRendering requires Application to be graphical!");
            return;
        }

        auto& cm = app.getComponentManager();

        if(!cm.hasComponent<MeshComponent>(entity)) {
            LILA_WARN("Entity does not have a MeshComponent!");
            return;
        }

        auto& mesh = cm.getComponent<MeshComponent>(entity);

        geometryMap_S[entity] = unique<OpenGL::GLGeometry>(mesh.vertices, mesh.indices);
        shaderMap_S[entity] = unique<OpenGL::GLShader>(mesh.vertexPath, mesh.fragmentPath);
    }

    /* Create two maps (u64 = entity, entity is a number)
     * - map<u64, Mesh/Geometry>
     * - map<u64, Shader>
     *
     * Renderer manages the Meshes and Shaders of each entity.
     */
    inline void render() {
        for(const auto&[entity, geometry] : geometryMap_S) {
            const auto& shader = shaderMap_S.at(entity);

            shader->bind();
            geometry->render();
            shader->bind();
        }
    }

    inline void destroy() {
        for(const auto &geometry: geometryMap_S | std::views::values)
            geometry->destroy();

        for(const auto &shader: shaderMap_S | std::views::values)
            shader->destroy();

        geometryMap_S.clear();
        shaderMap_S.clear();
    }

} // namespace Lila::Testing
