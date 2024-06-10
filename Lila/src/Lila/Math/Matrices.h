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
			data_m[0]  = v00; data_m[1]  = v01; data_m[2]  = v02; data_m[3]  = v03;
			data_m[4]  = v10; data_m[5]  = v11; data_m[6]  = v12; data_m[7]  = v13;
			data_m[8]  = v20; data_m[9]  = v21; data_m[10] = v22; data_m[11] = v23;
			data_m[12] = v30; data_m[13] = v31; data_m[14] = v32; data_m[15] = v33;
		}

		Mat4() {
			data_m[0] = 1.0f; 
			data_m[5] = 1.0f;
			data_m[10] = 1.0f;
			data_m[15] = 1.0f;
		}

		void set(i32 m, i32 n, f32 v) {
			data_m[m * 4 + n] = v;
		}

		f32 get(i32 m, i32 n) {
			return data_m[m * 4 + n];
		}

		f32* getAll() {
			return &data_m[0];
		}

	private:
		f32 data_m[16]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
	};

	Mat4 orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);
	Mat4 perspective(f32 fov, f32 aspectRatio, f32 near, f32 far);

	Mat4 translation(Vec3 position);
	Mat4 rotation(Vec3 rotation);
	Mat4 scale(Vec3 scale);

	
	Mat4 multiply(Mat4 a, Mat4 b);
}