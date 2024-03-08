#pragma once

#include "Logger.h"

#include "glad/glad.h"

#include <iostream>

namespace Lila {

	class FrameBuffer {
	public:
		FrameBuffer();
		~FrameBuffer();

		void SetData(const void* data, unsigned int size);

		void Bind();
		void Unbind();
		void Delete();

		unsigned int getColorAttachment() { return m_color; };

		unsigned int width, height;

		bool SwapTarget = false;

		void Create();
	private:
		unsigned int fbo, m_color, m_depth;
	};

}