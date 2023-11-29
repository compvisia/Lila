#pragma once

namespace Lila {

	struct FrameSpecs {
		unsigned int width, height;

		bool SwapTarget = false;
	};

	class FrameBuffer {
	public:
		FrameBuffer(FrameSpecs spec);
		~FrameBuffer();

		void SetData(const void* data, unsigned int size);

		void Bind();
		void Unbind();
		void Delete();

		unsigned int getColorAttachment() { return m_color; };

		FrameSpecs getSpecification() { return m_spec; }

	private:
		void Create();

		FrameSpecs m_spec;

		unsigned int fbo, m_color, m_depth;
	};

}