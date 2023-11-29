#include "Mat4.h"

namespace Lila {

	void Mat4::set(int m, int n, float value) {
		elements[m * 4 + n] = value;
	}
	float Mat4::get(int m, int n) {
		return elements[m * 4 + n];
	}

	float* Mat4::getAll() {
		return &elements[0];
	}

	void Mat4::fill(float value) {
		for (int m = 0; m < 4; m++)
			for (int n = 0; n < 4; n++)
				elements[m * 4 + n] = value;
	}

	// Static Members

	Mat4 Mat4::identity() {
		Mat4 result;

		result.set(0, 0, 1);
		result.set(1, 1, 1);
		result.set(2, 2, 1);
		result.set(3, 3, 1);

		return result;
	}

	Mat4 Mat4::translate(float x, float y, float z) {
		Mat4 result = identity();

		result.set(3, 0, x);
		result.set(3, 1, y);
		result.set(3, 2, z);

		return result;
	}

	Mat4 Mat4::rotate(float x, float y, float z) {
		Mat4 rotX = identity(), rotY = identity(), rotZ = identity();

		float Rx = radians(x);
		float Ry = radians(y);
		float Rz = radians(z);

		rotX.set(1,1,  cos(Rx));
		rotX.set(1,2, -sin(Rx));
		rotX.set(2,1,  sin(Rx));
		rotX.set(2,2,  cos(Rx));

		rotY.set(0,0,  cos(Ry));
		rotY.set(0,2,  sin(Ry));
		rotY.set(2,0, -sin(Ry));
		rotY.set(2,2,  cos(Ry));

		rotZ.set(0,0,  cos(Rz));
		rotZ.set(0,1, -sin(Rz));
		rotZ.set(1,0,  sin(Rz));
		rotZ.set(1,1,  cos(Rz));

		return multiply(multiply(rotZ, rotY), rotX);
	}

	Mat4 Mat4::scale(float x, float y, float z) {
		Mat4 result = identity();

		result.set(0, 0, x);
		result.set(1, 1, y);
		result.set(2, 2, z);

		return result;
	}

	Mat4 Mat4::transform(float x, float y, float z, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz) {
		Mat4 result;

		Mat4 trans = translate(x, y, z);
		Mat4 rot = rotate(Rx, Ry, Rz);
		Mat4 scalar = scale(Sx, Sy, Sz);

		result = multiply(multiply(scalar, rot), trans);

		return result;
	}

	Mat4 Mat4::perspective(float aspect, float fov, float f, float n) {
		Mat4 result = identity();

		float tanF = tan(radians(fov / 2));
		float range = f - n;

		result.set(0, 0, 1.0f / (aspect * tanF));
		result.set(1, 1, 1.0f / tanF);
		result.set(2, 2, -((f + n) / range));
		result.set(2, 3, -((2 * f * n) / range));

		result.set(3, 2, -1);

		return result;
	}

	Mat4 Mat4::orthographic(float l, float r, float t, float b, float f, float n) {
		Mat4 result = identity();

		result.set(0, 0, 2.0f / (r - l));
		result.set(1, 1, 2.0f / (t - b));
		result.set(2, 2, (-2.0f) / (f - n));

		result.set(0, 3, -(r + l) / (r - l));
		result.set(1, 3, -(t + b) / (t - b));
		result.set(2, 3, -(f + n) / (f - n));

		return result;
	}

	Mat4 Mat4::multiply(Mat4 first, Mat4 second) {
		Mat4 result = identity();

		for (int m = 0; m < 4; m++)
			for (int n = 0; n < 4; n++)
				result.set(m, n, 
					first.get(m, 0) * second.get(0, n) +
					first.get(m, 1) * second.get(1, n) +
					first.get(m, 2) * second.get(2, n) +
					first.get(m, 3) * second.get(3, n)
				);

		return result;
	}

}