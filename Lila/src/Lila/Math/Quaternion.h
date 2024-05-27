#pragma once

#include "Platform/Defines.h"

namespace Lila {

	class Quaternion {
	public:
		Quaternion(f32 a, f32 b, f32 c, f32 d) {
			val[0] = a;
			val[1] = b;
			val[2] = c;
			val[3] = d;
		}

	private:
		f32 val[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
	};
}