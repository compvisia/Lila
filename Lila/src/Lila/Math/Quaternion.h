#pragma once

#include "Platform/Defines.h"

namespace Lila {

	class Quaternion {
	public:
		Quaternion(f32 a, f32 b, f32 c, f32 d) {
			val_m[0] = a;
			val_m[1] = b;
			val_m[2] = c;
			val_m[3] = d;
		}

	private:
		f32 val_m[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
	};
}