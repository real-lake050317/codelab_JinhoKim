#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD__COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Test", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	
	std::cout << "OPENGL version: " << glGetString(GL_VERSION) << std::endl;
	
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
		glViewwport(0, 0, width, height);
	});
	
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwaapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	
	return 0;
}
