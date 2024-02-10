#include "Camera.h"

#include <math.h>
#include "Lila/utils/math.h"

namespace Lila {

	void Camera::update() {
		if (keyboard.isKeyDown(GLFW_KEY_SPACE)) {
			position.subY(0.001f);
		}
		if (keyboard.isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
			position.addY(0.001f);
		}
		if (keyboard.isKeyDown(GLFW_KEY_W)) {
			position.addX(-sinf(radians(rotation.Y())) * 0.001f);
			position.addZ(-cosf(radians(rotation.Y())) * 0.001f);
		}
		if (keyboard.isKeyDown(GLFW_KEY_S)) {
			position.addX(sinf(radians(rotation.Y())) * 0.001f);
			position.addZ(cosf(radians(rotation.Y())) * 0.001f);
		}
		if (keyboard.isKeyDown(GLFW_KEY_A)) {
			position.addX(-sinf(radians(rotation.Y()-90)) * 0.001f);
			position.addZ(-cosf(radians(rotation.Y()-90)) * 0.001f);
		}
		if (keyboard.isKeyDown(GLFW_KEY_D)) {
			position.addX(sinf(radians(rotation.Y() - 90)) * 0.001f);
			position.addZ(cosf(radians(rotation.Y() - 90)) * 0.001f);
		}

		rotation.setY((mouse.getPosition().X() - 1280 / 2.0f) * 0.075f);
		rotation.setX((mouse.getPosition().Y() - 720 / 2.0f) * 0.075f);
	}

}