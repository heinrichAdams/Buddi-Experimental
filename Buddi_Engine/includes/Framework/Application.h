#ifndef Application_H
#define Application_H

#include <SFML/Graphics.hpp>
#include "Framework/Core.h"

namespace Buddi_Base
{
	class Scene;
	class Application
	{
	public:
		Application();
		void Run();

		template<typename SceneType>
		weak<SceneType> LoadScene();

	private:
		void InternalUpdate(float deltaTime);
		void InternalRender();

		virtual void Update(float deltaTime);
		virtual void Render();

		sf::RenderWindow _window;
		float _targetFrameRate;
		sf::Clock _tick;

		shared<Scene> _currentScene;

	};

	template<typename SceneType>
	weak<SceneType> Application::LoadScene()
	{
		shared<SceneType> newScene{ new SceneType{this} };
		_currentScene = newScene;
		return newScene;
	}
}

#endif