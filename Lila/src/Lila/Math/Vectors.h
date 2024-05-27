#pragma once

#include "Platform/Defines.h"

namespace Lila {
	
	class Vec2 {
	public:
		Vec2(f32 x, f32 y) { 
			val[0] = x;
			val[1] = y;
		}

		f32 x() { return val[0]; }
		f32 y() { return val[1]; }

		f32 x(f32 x) { val[0] = x; return val[0]; }
		f32 y(f32 y) { val[1] = y; return val[1]; }

	private:
		f32 val[2] { 0.0f, 0.0f };
	};

	class Vec3 {
	public:
		Vec3(f32 x, f32 y, f32 z) {
			val[0] = x;
			val[1] = y;
			val[2] = z;
		}

		f32 x() { return val[0]; }
		f32 y() { return val[1]; }
		f32 z() { return val[2]; }

		f32 x(f32 x) { val[0] = x; return val[0]; }
		f32 y(f32 y) { val[1] = y; return val[1]; }
		f32 z(f32 z) { val[2] = z; return val[2]; }

	private:
		f32 val[3]{ 0.0f, 0.0f, 0.0f };
	};

	class Vec4 {
	public:
		Vec4(f32 x, f32 y, f32 z, f32 w) {
			val[0] = x;
			val[1] = y;
			val[2] = z;
			val[3] = w;
		}

		f32 x() { return val[0]; }
		f32 y() { return val[1]; }
		f32 z() { return val[2]; }
		f32 w() { return val[3]; }

		f32 x(f32 x) { val[0] = x; return val[0]; }
		f32 y(f32 y) { val[1] = y; return val[1]; }
		f32 z(f32 z) { val[2] = z; return val[2]; }
		f32 w(f32 w) { val[3] = w; return val[3]; }

	private:
		f32 val[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
	};
}