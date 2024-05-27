#pragma once

#include "Vectors.h"

#include "Platform/Defines.h"

namespace Lila {

	class Mat4 {
	public:
		Mat4(f32 v00, f32 v01, f32 v02, f32 v03,
			 f32 v10, f32 v11, f32 v12, f32 v13,
			 f32 v20, f32 v21, f32 v22, f32 v23,
			 f32 v30, f32 v31, f32 v32, f32 v33) {
			data[0]  = v00; data[1]  = v01; data[2]  = v02; data[3]  = v03;
			data[4]  = v10; data[5]  = v11; data[6]  = v12; data[7]  = v13;
			data[8]  = v20; data[9]  = v21; data[10] = v22; data[11] = v23;
			data[12] = v30; data[13] = v31; data[14] = v32; data[15] = v33;
		}

		Mat4() {
			data[0] = 1.0f; 
			data[5] = 1.0f;
			data[10] = 1.0f;
			data[15] = 1.0f;
		}

		void set(i32 m, i32 n, f32 v) {
			data[m * 4 + n] = v;
		}

		f32 get(i32 m, i32 n) {
			return data[m * 4 + n];
		}

		f32* getAll() {
			return &data[0];
		}

	private:
		f32 data[16]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
	};

	Mat4 orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);
	Mat4 perspective(f32 fov, f32 aspectRatio, f32 near, f32 far);

	Mat4 translation(Vec3 position);
	Mat4 rotation(Vec3 rotation);
	Mat4 scale(Vec3 scale);

	
	Mat4 multiply(Mat4 a, Mat4 b);
}