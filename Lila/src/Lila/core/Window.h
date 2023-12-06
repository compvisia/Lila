#pragma once

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include "Lila/utils/Vectors.h"

namespace Lila {

	class Window {
	public:
		Window(char* title, int width, int height);
		~Window();

		void Update();
		void Delete();

		int windowClose();

		Lila::Vec2 getSize();
		GLFWwindow* getWindow();

	private:
		void Create();

		char* m_title;
		int m_width, m_height;

		GLFWwindow* m_window;


	};

}

