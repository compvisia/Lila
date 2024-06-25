#pragma once

#include "GLSuccess.h"

#include "Lila/Rendering/Geometry.h"

#include "Platform/Defines.h"
#include "Platform/Graphics.h"

#include <vector>

namespace OpenGL {

	class GLGeometry : public Lila::Geometry {
	public:
		GLGeometry(std::vector<f32> vertices, std::vector<u32> indices);
		GLGeometry(std::vector<f32> vertices, std::vector<u32> indices, Lila::GeometryType type);
		~GLGeometry();

		void render() override;

	protected:
		void create() override;
		void destroy() override;
	
	private:
		void setupType();
	};

} // namespace OpenGL