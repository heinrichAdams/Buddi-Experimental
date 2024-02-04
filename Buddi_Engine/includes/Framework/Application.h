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
		Application(unsigned int wWidth, unsigned int wHeight, 
			const std::string& title, sf::Uint32 mode);
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
		_currentScene->InternalSceneStart();
		return newScene;
	}
}

#endif