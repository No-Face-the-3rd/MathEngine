#include "Window.h"
#include <GL/glew.h>


bool Window::init(unsigned int Width = 800, unsigned int Height = 600, const char *Title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();

	window = glfwCreateWindow(width, height, Title, nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);
	glEnable(GL_CULL_FACE);

	isInit = window;
	return isInit;
}

bool Window::step()
{
	INIT_ASSERT(Window);
	glfwSwapBuffers(window);
	return !glfwWindowShouldClose(window);
}
void Window::term(bool shouldClose)
{
	glfwSetWindowShouldClose(window, shouldClose);
	if (shouldClose)
		glfwTerminate();
}