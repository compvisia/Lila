#include <iostream>

#include <glad/glad.h>
#include <glfw/glfw3.h>

int main(int argc, char** argv) {

    printf("Hello World. I am Lila\n");

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    
    if(!glfwInit()) {
        printf("GLFW Failed! Error code: %d\n", glfwGetError(nullptr));
        return 0;
    }

    printf("GLFW version %d.%d.%d\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("GLAD Failed!\n");
        return 0;
	}

    printf("OpenGL version %s\n", glGetString(GL_VERSION));

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