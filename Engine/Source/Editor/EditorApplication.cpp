#include "EditorApplication.h"


EditorApplication::EditorApplication(int argc, char **argv)
{
	logger::init(argc, argv);
}

EditorApplication::~EditorApplication()
{

}

void EditorApplication::Run()
{
	while (true)
	{

	}
}


Application* CreateApplication(int argc, char** argv)
{
	return new EditorApplication(argc, argv);
}