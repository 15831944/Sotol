#pragma once

#include <Core/Application/Application.h>
#include <Core/Application/Log.h>

class EditorApplication : public Application
{
public:
	EditorApplication(int argc, char** argv);
	~EditorApplication();

	void Run();

private:

};