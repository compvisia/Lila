#pragma once

#include "Lila/Lila.h"

namespace Lila {

	class Camera {
	public:
		//Lila::Mat4 view;
		//Lila::Vec3 position = Lila::Vec3(0,0,0), rotation = Lila::Vec3(0,0,0);

		MeshSpecs* meshSpecs;

		Camera() {}

		~Camera() {}

		void update() {
			//view = Lila::Mat4::transform(position, rotation, Lila::Vec3(1, 1, 1));
			if (keyboard.isKeyDown(GLFW_KEY_SPACE)) {
				meshSpecs->cam_pos.setY(meshSpecs->cam_pos.Y() - 0.001f);
			}
			if (keyboard.isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
				meshSpecs->cam_pos.setY(meshSpecs->cam_pos.Y() + 0.001f);
			}
			if (keyboard.isKeyDown(GLFW_KEY_W)) {
				meshSpecs->cam_pos.setZ(meshSpecs->cam_pos.Z() - 0.001f);
			}
			if (keyboard.isKeyDown(GLFW_KEY_S)) {
				meshSpecs->cam_pos.setZ(meshSpecs->cam_pos.Z() + 0.001f);
			}
			if (keyboard.isKeyDown(GLFW_KEY_A)) {
				meshSpecs->cam_pos.setX(meshSpecs->cam_pos.X() + 0.001f);
			}
			if (keyboard.isKeyDown(GLFW_KEY_D)) {
				meshSpecs->cam_pos.setX(meshSpecs->cam_pos.X() - 0.001f);
			}
		}

		Keyboard keyboard;
		Mouse mouse;
	};

}