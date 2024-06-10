#include "Window.h"

#include "Logger.h"

#include "Platform/Dependencies.h"

namespace Lila {

	Window::Window(std::string name) {
		name_m = name;

		maximized_m = false;
		fullscreen_m = false;

	#ifdef LILA_GLFW_CONTEXT
		monitor_m = glfwGetPrimaryMonitor();
		videoMode_m = glfwGetVideoMode(monitor_m);

		width_m = videoMode_m->width / 1.5f;
		height_m = videoMode_m->height / 1.5f;

		refreshRate_m = videoMode_m->refreshRate;
	
		lila_info("Creating window");
	#else
		lila_info("Creating headless window");
	#endif
		create();
	}

	Window::Window(std::string name, b8 maximized) {
		name_m = name;

		maximized_m = true;
		fullscreen_m = false;
	#ifdef LILA_GLFW_CONTEXT
		monitor_m = glfwGetPrimaryMonitor();
		videoMode_m = glfwGetVideoMode(monitor_m);

		width_m = videoMode_m->width;
		height_m = videoMode_m->height;

		refreshRate_m = videoMode_m->refreshRate;

		lila_info("Creating window");
	#else
		lila_info("Creating headless window");
	#endif
		create();
	}

	Window::Window(std::string name, i32 width, i32 height) {
		name_m = name;

		width_m = width;
		height_m = height;
	#ifdef LILA_GLFW_CONTEXT
		maximized_m = false;
		fullscreen_m = false;

		monitor_m = glfwGetPrimaryMonitor();
		videoMode_m = glfwGetVideoMode(monitor_m);

		refreshRate_m = videoMode_m->refreshRate;

		if(videoMode_m->width < width_m || videoMode_m->height < height_m) {
			lila_warn("Window size too big. Enabling maximized mode");
			maximized_m = true;
			width_m = videoMode_m->width;
			height_m = videoMode_m->height;
		}

		lila_info("Creating window");
	#else
		lila_info("Creating headless window");
	#endif
		create();
	}

	Window::~Window() {
		lila_info("Deleting window");
	#ifdef LILA_GLFW_CONTEXT
		glfwDestroyWindow(window_m);
		glfwTerminate();
	#endif
	}

	void Window::create() {
	#ifdef LILA_GLFW_CONTEXT
		lila_info("Window size: %dx%d", width_m, height_m);
	
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if(maximized_m)
			glfwWindowHint(GLFW_MAXIMIZED, 1);

		window_m = glfwCreateWindow(width_m, height_m, name_m.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(window_m);

		initOpenGL();

		glfwSwapInterval(0);
		glfwShowWindow(window_m);
	#endif
	}

	void Window::render() {
	#ifdef LILA_OPENGL_CONTEXT
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);
	#endif
	}
	void Window::update() {
	#ifdef LILA_GLFW_CONTEXT
		glfwPollEvents();
		glfwSwapBuffers(window_m);

		glfwGetWindowSize(window_m, &tempWidth_m, &tempHeight_m);
		if(width_m == tempWidth_m && height_m == tempHeight_m)
			return;

		width_m = tempWidth_m;
		height_m = tempHeight_m;

	#ifdef LILA_OPENGL_CONTEXT
		glViewport(0, 0, width_m, height_m);
	#endif
	#endif
	}

	bool Window::isOpen() {
	#ifdef LILA_GLFW_CONTEXT
		return !glfwWindowShouldClose(window_m);
	#else
		return false;
	#endif
	}
	bool Window::isClosed() {
	#ifdef LILA_GLFW_CONTEXT
		return glfwWindowShouldClose(window_m);
	#else
		return true;
	#endif
	}
}