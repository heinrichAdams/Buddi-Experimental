#ifndef Application_H
#define Application_H

#include <SFML/Graphics.hpp>

namespace Buddi_Base
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		sf::RenderWindow _window;

	};
}

#endif