#pragma once

#include "Lila/Core/Logger.h"

#include "Graphics.h"

/**
 * Initializes all dependencies used for Lila excluding render context
*/
static bool initDependencies() {
#ifdef LILA_GLFW_CONTEXT
	if(!glfwInit()) {
		lila_fatal("Failed to initialize GLFW!")
		return false;
	}

	lila_trace("Initialized GLFW");
	lila_info("GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
#else
	lila_warn("GLFW not defined, going into headless mode!");
#ifndef LILA_HEADLESS_CONTEXT
#define LILA_HEADLESS_CONTEXT
#endif
#endif
	return true;
}

/**
 * Initializes OpenGL by getting the window pointer.
*/
static bool initOpenGL() {
#ifdef LILA_OPENGL_CONTEXT
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		lila_fatal("Failed to initialize OpenGL!")
		return false;
	}

	lila_trace("Initialized OpenGL");
	lila_info("OpenGL version %s", glGetString(GL_VERSION));
#else
	lila_warn("Did not initialize OpenGL!");
#endif
	return true;
}