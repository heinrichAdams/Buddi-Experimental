#include "EntryPoint.h"
#include "Framework/Application.h"

int main()
{
	Buddi_Base::Application* app = GetApplication();
	app->Run();

	delete app;
	return 0;
}