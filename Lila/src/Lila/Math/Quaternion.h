#pragma once

namespace Lila {

	class Quaternion {
	public:
		Quaternion(float a, float b, float c, float d) {
			val[0] = a;
			val[1] = b;
			val[2] = c;
			val[3] = d;
		}

	private:
		float val[4]{ 0.0f, 0.0f, 0.0f, 0.0f };
	};
}