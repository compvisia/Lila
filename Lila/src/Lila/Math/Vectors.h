#pragma once

namespace Lila {
	
	class Vec2 {
	public:
		Vec2(float x, float y) { 
			val[0] = x;
			val[1] = y;
		}

		float x() { return val[0]; }
		float y() { return val[1]; }

		float x(float x) { val[0] = x; return val[0]; }
		float y(float y) { val[1] = y; return val[1]; }

	private:
		float val[2] { 0.0f, 0.0f };
	};

	class Vec3 {
	public:
		Vec3(float x, float y, float z) {
			val[0] = x;
			val[1] = y;
			val[2] = z;
		}

		float x() { return val[0]; }
		float y() { return val[1]; }
		float z() { return val[2]; }

		float x(float x) { val[0] = x; return val[0]; }
		float y(float y) { val[1] = y; return val[1]; }
		float z(float z) { val[2] = z; return val[2]; }

	private:
		float val[3]{ 0.0f, 0.0f, 0.0f };
	};

	class Vec4 {
	public:
		Vec4(float x, float y, float z, float w) {
			val[0] = x;
			val[1] = y;
			val[2] = z;
			val[3] = w;
		}

		float x() { return val[0]; }
		float y() { return val[1]; }
		float z() { return val[2]; }
		float w() { return val[3]; }

		float x(float x) { val[0] = x; return val[0]; }
		float y(float y) { val[1] = y; return val[1]; }
		float z(float z) { val[2] = z; return val[2]; }
		float w(float w) { val[3] = w; return val[3]; }

	private:
		float val[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
	};
}