#pragma once

#include "Platform/Defines.h"

#include <vector>

namespace Lila {

    /**
     * @brief An enum used for all types of Geometry.
     * 
     * This is used to determine the size of 1 vertex.
     * OpenGL influences: glVertexAttribPointer()
    */
	typedef enum GeometryType {
		GEOMETRY_XYZ,
		GEOMETRY_XYZ_UV,
		GEOMETRY_XYZ_RGB,
		GEOMETRY_XYZ_RGB_UV,
	};

	class Geometry {
	public:
		virtual ~Geometry() {}

		virtual void render() = 0;

	protected:
		virtual void create() = 0;
		virtual void destroy() = 0;

	protected:
		GeometryType type_m;

		std::vector<f32> vertices_m;
		std::vector<u32> indices_m;

		u32 vao_m, vbo_m, ebo_m;
	};

} // namespace Lila