#include "FrameBuffer.h"

#include "glad/glad.h"

#include <iostream>

namespace Lila {

	FrameBuffer::FrameBuffer() {
	}

	FrameBuffer::~FrameBuffer() {
		Delete();
	}

	void FrameBuffer::SetData(const void* data, unsigned int size) {

	}

	void FrameBuffer::Bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	}

	void FrameBuffer::Unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::Delete() {
		glDeleteTextures(1, &m_depth);
		glDeleteTextures(1, &m_color);
		glDeleteFramebuffers(1, &fbo);
	}

	void FrameBuffer::Create() {
		glGenFramebuffers(1, &fbo);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glGenTextures(1, &m_color);
		glBindTexture(GL_TEXTURE_2D, m_color);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_color, 0);

		glGenTextures(1, &m_depth);
		glBindTexture(GL_TEXTURE_2D, m_depth);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, width, height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_depth, 0);
		
		if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			printf("Framebuffer is Incomplete!\n");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

}