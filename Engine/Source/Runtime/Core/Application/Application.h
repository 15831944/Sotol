#pragma once

// Template for the entrypoint of any applications

#include <Core/Core.h>

class Application
{
public:
	Application(int argc, char** argv);
	virtual ~Application();

	void Run();
};

Application* CreateApplication(int argc, char** argv);