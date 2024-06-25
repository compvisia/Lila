#include "GLGeometry.h"

namespace OpenGL {

	GLGeometry::GLGeometry(std::vector<f32> vertices, std::vector<u32> indices) {
		vertices_m = vertices;
		indices_m = indices;
		
		type_m = Lila::GEOMETRY_XYZ;

		create();
	}

	GLGeometry::GLGeometry(std::vector<f32> vertices, std::vector<u32> indices, Lila::GeometryType type) {
		vertices_m = vertices;
		indices_m = indices;

		type_m = type;
		
		create();
	}

	GLGeometry::~GLGeometry() {
		destroy();
	}

	void GLGeometry::render() {
	#ifdef LILA_OPENGL_CONTEXT
		glBindVertexArray(vao_m);

		glDrawElements(GL_TRIANGLES, indices_m.size(), GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	#endif
	}

	void GLGeometry::create() {
	#ifdef LILA_OPENGL_CONTEXT
		glGenVertexArrays(1, &vao_m);
        glGenBuffers(1, &vbo_m);
        glGenBuffers(1, &ebo_m);

        glBindVertexArray(vao_m);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_m);
        glBufferData(GL_ARRAY_BUFFER, vertices_m.size() * sizeof(f32), &vertices_m[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_m);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_m.size() * sizeof(u32), &indices_m[0], GL_STATIC_DRAW);

        setupType();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	#endif
    }

	void GLGeometry::destroy() {
	#ifdef LILA_OPENGL_CONTEXT
		glDeleteBuffers(1, &vbo_m);
        glDeleteBuffers(1, &ebo_m);

        glDeleteVertexArrays(1, &vao_m);
	#endif
	}

	void GLGeometry::setupType() {
	#ifdef LILA_OPENGL_CONTEXT
		int size = 3;
		if(type_m == Lila::GEOMETRY_XYZ_UV)
			size = 5;
		if(type_m == Lila::GEOMETRY_XYZ_RGB)
			size = 6;
		if(type_m == Lila::GEOMETRY_XYZ_RGB_UV)
			size = 8;

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size * sizeof(f32), (void*)0);
		glEnableVertexAttribArray(0); // XYZ

		if(type_m == Lila::GEOMETRY_XYZ)
			return;

		if(type_m == Lila::GEOMETRY_XYZ_UV) {
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, size * sizeof(f32), (void*)(3 * sizeof(f32)));
			glEnableVertexAttribArray(1); // UV
			return;
		}

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, size * sizeof(f32), (void*)(3 * sizeof(f32)));
		glEnableVertexAttribArray(1); // RGB

		if(type_m == Lila::GEOMETRY_XYZ_RGB)
			return;

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, size * sizeof(f32), (void*)(6 * sizeof(f32)));
		glEnableVertexAttribArray(2); // UV
	#endif
	}

} // namespace OpenGL