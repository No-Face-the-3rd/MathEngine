#include "Asset.h"

#include "Window.h"

void Asset::loadTexture(const std::string &name, const char *path)
{
	assert(Window::instance().isInitialized() && "Window is not Initialized!");
}