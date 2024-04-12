#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Lila {

	Texture::Texture() {
		m_path = nullptr;
		Create();
	}

	Texture::Texture(const char* path) {
		m_path = path;
		Create();
	}

	Texture::~Texture() {
		Delete();
	}

	void Texture::Bind() {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_id);
	}
	void Texture::Unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Texture::Delete() {
		glDeleteTextures(1, &m_id);
	}


	void Texture::Create() {
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (m_path == nullptr) 
			return; 
	
		lila_info("Texture path is \"%s\"", m_path);

		unsigned char* img = stbi_load(m_path, &m_width, &m_height, &m_channel, 4);

		if(img == NULL) {
			lila_warn("Image failed to load!");
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(img);
	}

}