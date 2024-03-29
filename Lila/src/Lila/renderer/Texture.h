#pragma once

#include <glad/glad.h>

#include "Lila/core/Logger.h"

namespace Lila {

	class Texture {
	public:
		Texture();
		Texture(const char* path);
		~Texture();

		void Bind();
		void Unbind();
		void Delete();

	private:
		void Create();

		const char* m_path;
		unsigned int m_id;
		int m_width, m_height, m_channel;

	};

}