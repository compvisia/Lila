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

		int tempW = width, tempH = height;
		glfwGetWindowSize(window, &width, &height);

		if(tempW != width || tempH != height) {
			glViewport(0, 0, width, height);
			//WindowEvent event(this, EventType::WindowResized);
			//eventhandler.releaseEvent(event);
		}
	}
	void Window::Delete() {
		//WindowEvent event(this, EventType::WindowDestroyed);
		//eventhandler.releaseEvent(event);
		glfwDestroyWindow(window);
		lila_info("Deleted window successfully");
		glfwTerminate();
		lila_info("Terminated GLFW");
	}

	int Window::windowClose() { return glfwWindowShouldClose(window); }

	Lila::Vec2 Window::getSize() { return Lila::Vec2(width, height); }
	GLFWwindow* Window::getWindow() { return window; }

	void Window::Create() {

		if(!glfwInit()) {
			lila_fatal("Failed to Initialize GLFW!");
			abort();
		}
		lila_trace("Initialized GLFW");
		lila_info("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

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
			lila_info("No Vulkan support, switching to OpenGL");

			if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				lila_fatal("Failed to Initialize OpenGL!");
				abort();
			}
			lila_trace("Initialized OpenGL");
			lila_info("OpenGL version %s", glGetString(GL_VERSION));

			glViewport(0, 0, width, height);
		}

		glfwShowWindow(window);

		lila_info("Created Window successfully");
		lila_info("Window size %dx%d", width, height);

		//WindowEvent event(this, EventType::WindowCreated);
		//eventhandler.releaseEvent(event);
	}

}