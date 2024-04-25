#pragma once

#include "Logger.h"
#include "Lila/math/Math.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Lila {

	class Window {
	public:
		Window(std::string name);
		Window(std::string name, bool maximized);
		Window(std::string name, int width, int height);
		~Window();

		GLFWwindow* getContext() { return window_m; }
		std::string getName() { return name_m; }
		Vec2 getSize() { return Vec2{ (float)width_m, (float)height_m }; }



	private:
		void create();

	private:
		GLFWwindow* window_m;

		std::string name_m;
		int x_m, y_m;
		int width_m, height_m;
		int refreshRate_m;
		bool maximized_m;
		bool fullscreen_m;
		GLFWmonitor* monitor_m;
		const GLFWvidmode* videoMode_m;
	};

}