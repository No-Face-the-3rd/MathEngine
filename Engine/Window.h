#pragma once


#ifndef WINDOW_H
#define WINDOW_H

#include <cassert>
#include <typeinfo>
#include <GLFW/glfw3.h>

#define INIT_ASSERT(name) assert(isInit && #name "not initialized!")

class Window
{
	bool isInit;
	unsigned int width, height;
	GLFWwindow *window;
	Window() : isInit(false)
	{

	}
public:
	static Window &instance()
	{
		static Window i; 
		return i;
	}

	bool init(unsigned int Width = 800, unsigned int Height = 600, const char *Title = "Engine");
	bool step();
	void term(bool shouldClose = false);

	unsigned int getWidth()
	{
		INIT_ASSERT(Window);
		return width;
	}
	unsigned int getHeight()
	{
		INIT_ASSERT(Window);
		return height;
	}
	bool isInitialized()
	{
		return isInit;
	}
};


#endif