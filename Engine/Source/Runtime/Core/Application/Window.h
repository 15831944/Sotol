#pragma once


#include <GLFW/glfw3.h>

enum WindowMode
{
	MINIMIZED,
	WINDOWED,
	FULLSCREEN,
	BORDERLESS_WINDOW
};

struct WindowCreateInfo
{
	const std::string Name;
};
	

class Window
{
public:
	Window();
	Window(const WindowCreateInfo& CreateInfo);
	~Window();



private:
	GLFWwindow* pWindow;
};