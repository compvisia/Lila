#include "Window.h"

namespace Lila {

	Window::Window(const char* title, int width, int height) {
		this->title  = title;
		this->width  = width;
		this->height = height;

		Create();
	}


	Window::~Window() {
		Delete();
	}

	void Window::Update() {
		glfwSwapBuffers(window);
		glfwPollEvents();

		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);
	}
	void Window::Delete() {
		glfwDestroyWindow(window);
		info("Deleted window successfully");
		glfwTerminate();
		info("Terminated GLFW");
	}

	int Window::windowClose() { return glfwWindowShouldClose(window); }

	Lila::Vec2 Window::getSize() { return Lila::Vec2(width, height); }
	GLFWwindow* Window::getWindow() { return window; }

	void Window::Create() {

		if(!glfwInit()) {
			fatal("Failed to Initialize GLFW!");
			abort();
		}
		trace("Initialized GLFW");
		info("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title, nullptr, nullptr);

		glfwMakeContextCurrent(window);
		glfwSwapInterval(0);

		bool vulkan = false;
		if(vulkan) {
			// LONG TODO: Vulkan Support
		} else {
			info("No Vulkan support, switching to OpenGL");

			if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				fatal("Failed to Initialize OpenGL!");
				abort();
			}
			trace("Initialized OpenGL");
			info("OpenGL version %s", glGetString(GL_VERSION));

			glViewport(0, 0, width, height);
		}

		glfwShowWindow(window);

		info("Created Window successfully");
		info("Window size %dx%d", width, height)
	}

}