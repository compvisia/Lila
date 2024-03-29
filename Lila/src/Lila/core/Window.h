#pragma once

#include "Lila/core/Logger.h"

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include "Lila/utils/Vectors.h"

namespace Lila {

	class Window {
	public:
		Window(const char* title, int width, int height);
		~Window();

		void Update();
		void Delete();

		int windowClose();

		Lila::Vec2 getSize();
		GLFWwindow* getWindow();

	private:
		void Create();

		const char* title;
		int width, height;

		GLFWwindow* window;


	};

}

