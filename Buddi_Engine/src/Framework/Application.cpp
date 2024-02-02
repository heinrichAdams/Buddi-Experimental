#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/Scene.h"

namespace Buddi_Base
{
	Application::Application()
		: _window{sf::VideoMode(720,940), "Buddi"},
	      _targetFrameRate{ 60 },
		  _tick{},
		  _currentScene{nullptr}
	{
		 
	}

	void Application::Run()
	{
		_tick.restart();
		float runTime = 0.f;
		float targetTime = 1.f / _targetFrameRate;
		float frameDeltaTime = 0.f;
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
			frameDeltaTime = _tick.restart().asSeconds();
			runTime += frameDeltaTime;
			while (runTime > targetTime)
			{
				runTime -= targetTime;
				InternalUpdate(targetTime);
				InternalRender();
			}
		}
	}

	void Application::InternalUpdate(float deltaTime)
	{
		Update(deltaTime);
		if (_currentScene)
		{
			_currentScene->InternalSceneStart();
			_currentScene->InternalUpdate(deltaTime);
		}
	}

	void Application::InternalRender()
	{
		_window.clear();

		Render();

		_window.display();
	}

	void Application::Update(float deltaTime)
	{
	}

	void Application::Render()
	{
		sf::RectangleShape rect{ sf::Vector2f{100,100} };
		rect.setFillColor(sf::Color::Blue);
		rect.setPosition(_window.getSize().x / 2.f,
			_window.getSize().y / 2.f);

		_window.draw(rect);
	}
}