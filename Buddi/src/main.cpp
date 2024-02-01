#include <iostream>
#include <SFML\Graphics.hpp>
#include "Framework/Application.h"
#include <memory>

int main()
{
	std::unique_ptr<Buddi_Base::Application> app = 
		std::make_unique<Buddi_Base::Application>();

	app->Run();

	return 0;
}