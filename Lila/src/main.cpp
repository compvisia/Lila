#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "console/Logger.h"

int main(int argc, char** argv) {
    printf("Hello World. I am Lila\n");
    
    Lila::Logger logger;

    LOG_INFO(logger, "Successfully Booted up!");

    if(!glfwInit()) {
        LOG_ERROR(logger, "GLFW Failed! Error code: %d\n", glfwGetError(nullptr));
        return 0;
    }

    LOG_INFO(logger, "GLFW version %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Lila", NULL, NULL);

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERROR(logger, "GLAD Failed!");
        return 0;
	}

    LOG_INFO(logger, "Window Created!");

    LOG_INFO(logger, "OpenGL version %s", glGetString(GL_VERSION));

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9f, 0.5f, 0.81f, 1.0f);
    
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}