#pragma once

#include "math.h"
#include "Vectors.h"

namespace Lila {

	class Mat4 {
	public:	
		void set(int m, int n, float value);
		float get(int m, int n);

		float* getAll();

		void fill(float value);

		static Mat4 identity();

		static Mat4 translate(float x, float y, float z);
		static Mat4 rotate(float x, float y, float z);
		static Mat4 scale(float x, float y, float z);

		static Mat4 transform(float x, float y, float z, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz);
		static Mat4 transform(Vec3 vPosition, Vec3 vRotation, Vec3 vScale);

		static Mat4 perspective(float aspect, float fov, float f, float n);
		static Mat4 orthographic(float l, float r, float t, float b, float f, float n);

		static Mat4 multiply(Mat4 first, Mat4 second);

	private:
		float elements[16] = {};
	};

}