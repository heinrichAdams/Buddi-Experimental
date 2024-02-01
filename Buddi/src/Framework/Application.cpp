#include "Framework/Application.h"

namespace Buddi_Base
{
	Application::Application()
		: _window{sf::VideoMode(720,940), "Buddi"}
	{
		 
	}

	void Application::Run()
	{
		while (_window.isOpen())
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					_window.close();
				}
			}
		}
	}
}