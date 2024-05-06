#pragma once

#include "Vectors.h"

namespace Lila {

	class Mat4 {
	public:
		Mat4(float v00, float v01, float v02, float v03,
			 float v10, float v11, float v12, float v13,
			 float v20, float v21, float v22, float v23,
			 float v30, float v31, float v32, float v33) {
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

		void set(int m, int n, float v) {
			data[m * 4 + n] = v;
		}

		float get(int m, int n) {
			return data[m * 4 + n];
		}

		float* getAll() {
			return &data[0];
		}

	private:
		float data[16]{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
	};

	Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
	Mat4 perspective(float fov, float aspectRatio, float near, float far);

	Mat4 translation(Vec3 position);
	Mat4 rotation(Vec3 rotation);
	Mat4 scale(Vec3 scale);

	
	Mat4 multiply(Mat4 a, Mat4 b);
}