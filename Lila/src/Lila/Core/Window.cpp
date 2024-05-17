#include "Window.h"

#include "Logger.h"

#include "Platform/Dependencies.h"

namespace Lila {

	Window::Window(std::string name) {
		name_m = name;

		maximized_m = false;
		fullscreen_m = false;

		glfwInit();

		monitor_m = glfwGetPrimaryMonitor();
		videoMode_m = glfwGetVideoMode(monitor_m);

		width_m = videoMode_m->width / 1.5f;
		height_m = videoMode_m->height / 1.5f;

		refreshRate_m = videoMode_m->refreshRate;

		lila_info("Creating window");
		create();
	}

	Window::Window(std::string name, bool maximized) {
		name_m = name;

		maximized_m = true;
		fullscreen_m = false;

		monitor_m = glfwGetPrimaryMonitor();
		videoMode_m = glfwGetVideoMode(monitor_m);

		width_m = videoMode_m->width;
		height_m = videoMode_m->height;

		refreshRate_m = videoMode_m->refreshRate;

		lila_info("Creating window");
		create();
	}

	Window::Window(std::string name, int width, int height) {
		name_m = name;

		width_m = width;
		height_m = height;

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
		create();
	}

	Window::~Window() {
		lila_info("Deleting window");
		glfwDestroyWindow(window_m);
		glfwTerminate();
	}

	void Window::create() {
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
	}
}