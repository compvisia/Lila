#include "GLTexture.h"

#include <glad/glad.h>

#include "stb_image.h"

namespace OpenGL {

    GLTexture::GLTexture() {
        create();
    }

    GLTexture::GLTexture(std::filesystem::path path) {
        path_m = path;
        create();
    }

    GLTexture::~GLTexture() {
        glDeleteTextures(1, &id_m);
    }

    void GLTexture::bind() {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, id_m);
    }

    void GLTexture::unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void GLTexture::create() {
        glGenTextures(1, &id_m);
        glBindTexture(GL_TEXTURE_2D, id_m);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

         u8* imageData = stbi_load(path_m.string().c_str(), &width_m, &height_m, &channels_m, 0);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_m, height_m, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(imageData);
    }


} // namespace OpenGL
