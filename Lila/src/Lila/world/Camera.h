#pragma once

#include "Lila/utils/Vectors.h"
#include "Lila/input/Keyboard.h"
#include "Lila/input/Mouse.h"

namespace Lila {

	class Camera {
	public:
		Vec3 position = Vec3(0,0,0), rotation = Vec3(0,0,0);

		Camera(Keyboard keyboard, Mouse mouse) {
			this->keyboard = keyboard;
			this->mouse = mouse;
		}
		~Camera() {}

		void update();
	private:
		Keyboard keyboard;
		Mouse mouse;
	};

}