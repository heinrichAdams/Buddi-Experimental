#include "Framework/Application.h"
#include "Framework/Core.h"
#include "Framework/Scene.h"

namespace Buddi_Base
{
	Application::Application(unsigned int wWidth, unsigned int wHeight, 
		const std::string& title, sf::Uint32 mode)
		: _window{ sf::VideoMode(wWidth,wHeight), title, mode },
		_targetFrameRate{ 60 },
		_tick{},
		_currentScene{ nullptr }
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
		if (_currentScene)
		{
			_currentScene->Render(_window);
		}
	}
}