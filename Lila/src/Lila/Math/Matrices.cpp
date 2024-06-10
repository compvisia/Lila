#include "Matrices.h"

#include "Math.h"

namespace Lila {

	Mat4 orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far) {
		Mat4 result = Mat4();

		f32 rl = right - left;
		f32 tb = top - bottom;
		f32 fn = far - near;

		result.set(0, 0,  2.0f / rl);
		result.set(1, 1,  2.0f / tb);
		result.set(2, 2, -2.0f / fn);

		result.set(3, 0, (right + left) / rl);
		result.set(3, 1, (top + bottom) / tb);
		result.set(3, 2,   (far + near) / fn);

		return result;
	}
	Mat4 perspective(f32 fov, f32 aspectRatio, f32 near, f32 far) {
		Mat4 result = Mat4();

		f32 tanFov = tan(toRadians(fov/2));
		f32 range = (far - near);

		result.set(0, 0, 1.0f / (aspectRatio * tanFov));
		result.set(1, 1, 1.0f / tanFov);
		result.set(2, 2, -((far + near) / range));
		result.set(2, 3, -((2 * far * near) / range));

		result.set(3, 2, -1);
		result.set(3, 3,  1);

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

		f32 Rx = toRadians(rotation.x());
		f32 Ry = toRadians(rotation.y());
		f32 Rz = toRadians(rotation.z());

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

		for (i32 m = 0; m < 4; m++)
			for (i32 n = 0; n < 4; n++)
				result.set(m, n,
					a.get(m, 0) * b.get(0, n) +
					a.get(m, 1) * b.get(1, n) +
					a.get(m, 2) * b.get(2, n) +
					a.get(m, 3) * b.get(3, n)
				);

		return result;
	}
}