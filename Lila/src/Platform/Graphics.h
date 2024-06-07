#pragma once

#ifndef LILA_HEADLESS_CONTEXT
#define LILA_GLFW_CONTEXT
#define LILA_OPENGL_CONTEXT
#endif

#ifdef LILA_OPENGL_CONTEXT
#include <glad/glad.h>
#endif

#ifdef LILA_GLFW_CONTEXT
#include <GLFW/glfw3.h>
#endif