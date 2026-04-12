#include "MVP.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Log/Macros.h"

// TODO: Implement the correct coordinate system (LH +Z forward)
namespace Lila {

    // TODO: Reimplement Model Matrix
    glm::mat4 getModelMatrix(const Lila::ECS::Transform& transform) {
        glm::mat4 translate = glm::translate(glm::mat4(1.0f), transform.position);
        glm::mat4 rotate = glm::mat4_cast(glm::normalize(transform.rotation));
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), transform.scalar);

        return translate * rotate * scale;
    }

    // TODO: Reimplement View Matrix
    glm::mat4 getViewMatrix(const Lila::ECS::Transform& transform) {
        glm::quat q = glm::normalize(transform.rotation);

        glm::vec3 forward = q * glm::vec3(0, 0, 1);
        glm::vec3 up      = q * glm::vec3(0, 1, 0);
        glm::vec3 right   = q * glm::vec3(-1, 0, 0);

        glm::mat4 view(1.0f);

        view[0][0] = right.x;
        view[1][0] = right.y;
        view[2][0] = right.z;

        view[0][1] = up.x;
        view[1][1] = up.y;
        view[2][1] = up.z;

        view[0][2] = forward.x;
        view[1][2] = forward.y;
        view[2][2] = forward.z;

        view[3][0] = -glm::dot(right, transform.position);
        view[3][1] = -glm::dot(up, transform.position);
        view[3][2] = -glm::dot(forward, transform.position);

        return view;


        // glm::vec3 target  = transform.position + glm::vec3(0.0f, 0.0f, 1.0f);
        // glm::vec3 up      = glm::vec3(0.0f, 1.0f, 0.0f);

        // return glm::lookAt(transform.position, target, up);
    }

    // TODO: Reimplement Projection Matrix
    glm::mat4 getProjectionMatrix(const CameraComponent& camera, const Window& window) {
        if (camera.type == CameraType::None)
            return glm::mat4(1);

        if (camera.type == CameraType::Perspective) {
            const f32 fovRad = glm::radians(camera.fov);

            glm::mat4 projection = glm::perspective(
                fovRad,
                static_cast<f32>(window.getWidth())/window.getHeight(),
                camera.near,
                camera.far
            );
            projection[1][1] *= -1;

            return projection;
        }

        return glm::ortho(
            0.0f,
            static_cast<f32>(window.getWidth()),
            static_cast<f32>(window.getHeight()),
            0.0f,
            camera.near,
            camera.far
        );
    }

} // namespace Lila
