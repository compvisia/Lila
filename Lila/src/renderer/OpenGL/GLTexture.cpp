#include "GLTexture.h"

#include <glad/glad.h>

#include "platform/stbi.h"

namespace OpenGL {

GLTexture::GLTexture(std::filesystem::path texturePath) {
    texturePath_m = texturePath;
    LOG_INFO("%s", texturePath.string().c_str());

    create();
}

GLTexture::~GLTexture() {}

void GLTexture::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId_m);
}

void GLTexture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void GLTexture::destroy() {
    glDeleteTextures(1, &textureId_m);
}

void GLTexture::create() {
    glGenTextures(1, &textureId_m);
    glBindTexture(GL_TEXTURE_2D, textureId_m);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* imageData = stbi_load(texturePath_m.string().c_str(), &width_m, &height_m, &channels_m, 0);

    if(!imageData) {
        LOG_ERROR("Texture data couldn't be loaded!");
        return;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_m, height_m, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

} // namespace OpenGL