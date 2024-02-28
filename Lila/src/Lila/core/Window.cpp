#include "Window.h"

namespace Lila {

	Window::Window(char* title, int width, int height) {
		m_title  = title;
		m_width  = width;
		m_height = height;

		Create();
	}


	Window::~Window() {
		Delete();
	}

	void Window::Update() {
		glfwSwapBuffers(m_window);
		glfwPollEvents();

		glfwGetWindowSize(m_window, &m_width, &m_height);
		glViewport(0, 0, m_width, m_height);
	}
	void Window::Delete() {
		glfwDestroyWindow(m_window);
	}

	int Window::windowClose() { return glfwWindowShouldClose(m_window); }

	Lila::Vec2 Window::getSize() { return Lila::Vec2(m_width, m_height); }
	GLFWwindow* Window::getWindow() { return m_window; }

	void Window::Create() {

		if(!glfwInit()) {
			fatal("Failed to Initialize GLFW!");
			abort();
		}
		info("Initialized GLFW");
		info("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

		glfwMakeContextCurrent(m_window);
		glfwSwapInterval(0);

		bool vulkan = false;
		if(vulkan) {
			// LONG TODO: Vulkan Support
		} else {
			info("No Vulkan Support, Switching to OpenGL");

			if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				fatal("Failed to Initialize OpenGL!");
				abort();
			}
			info("Initialized OpenGL");
			info("OpneGL version %d.%d", GLVersion.major, GLVersion.minor);

			glViewport(0, 0, m_width, m_height);
		}

		glfwShowWindow(m_window);
	}

}