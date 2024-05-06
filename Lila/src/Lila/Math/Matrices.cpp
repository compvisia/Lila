#include "Matrices.h"

#include "Math.h"

namespace Lila {

	Mat4 orthographic(float left, float right, float bottom, float top, float near, float far) {
		Mat4 result = Mat4();

		float rl = right - left;
		float tb = top - bottom;
		float fn = far - near;

		result.set(0, 0,  2.0f / rl);
		result.set(1, 1,  2.0f / tb);
		result.set(2, 2, -2.0f / fn);

		result.set(3, 0, (right + left) / rl);
		result.set(3, 1, (top + bottom) / tb);
		result.set(3, 2,   (far + near) / fn);

		return result;
	}
	Mat4 perspective(float fov, float aspectRatio, float near, float far) {
		Mat4 result = Mat4();

		float tanFov = tan(toRadians(fov/2));
		float range = (far - near);

		result.set(0, 0, 1.0f / (aspectRatio * tanFov));
		result.set(1, 1, 1.0f / tanFov);
		result.set(2, 2, -((far + near) / range));
		result.set(2, 3, -((2 * far * near) / range));

		result.set(3, 2, -1);
		result.set(3, 3,  0);

		return result;
	}

	Mat4 translation(Vec3 position) {
		Mat4 result = Mat4();

		result.set(3, 0, position.x());
		result.set(3, 1, position.y());
		result.set(3, 2, position.z());

		return result;
	}
	Mat4 rotation(Vec3 rotation) {
		Mat4 x = Mat4(), y = Mat4(), z = Mat4();

		float Rx = toRadians(rotation.x());
		float Ry = toRadians(rotation.y());
		float Rz = toRadians(rotation.z());

		x.set(1, 1,  cos(Rx));
		x.set(1, 2, -sin(Rx));
		x.set(2, 1,  sin(Rx));
		x.set(2, 2,  cos(Rx));

		y.set(0, 0,  cos(Ry));
		y.set(0, 2,  sin(Ry));
		y.set(2, 0, -sin(Ry));
		y.set(2, 2,  cos(Ry));

		z.set(0, 0,  cos(Rz));
		z.set(0, 1, -sin(Rz));
		z.set(1, 0,  sin(Rz));
		z.set(1, 1,  cos(Rz));

		return multiply(multiply(z,y),x);
	}
	Mat4 scale(Vec3 scale) {
		Mat4 result = Mat4();

		result.set(0, 0, scale.x());
		result.set(1, 1, scale.y());
		result.set(2, 2, scale.z());

		return result;
	}

	Mat4 multiply(Mat4 a, Mat4 b) {
		Mat4 result = Mat4();

		for (int m = 0; m < 4; m++)
			for (int n = 0; n < 4; n++)
				result.set(m, n,
					a.get(m, 0) * b.get(0, n) +
					a.get(m, 1) * b.get(1, n) +
					a.get(m, 2) * b.get(2, n) +
					a.get(m, 3) * b.get(3, n)
				);

		return result;
	}
}