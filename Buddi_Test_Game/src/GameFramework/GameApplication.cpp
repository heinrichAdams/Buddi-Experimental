#include <SFML/Graphics.hpp>
#include "GameFramework/GameApplication.h"
#include "Framework/Scene.h"
#include "Framework/Actor.h"
#include "Framework/Core.h"

Buddi_Base::Application* GetApplication()
{
	return new Game::GameApplication{};
}

namespace Game
{
	GameApplication::GameApplication()
		:	Application{600, 980, "Buddi_Test_Game", 
			sf::Style::Titlebar | sf::Style::Close }
	{
		Buddi_Base::weak<Buddi_Base::Scene> newScene = 
			Buddi_Base::Application::LoadScene<Buddi_Base::Scene>();

		newScene.lock()->CreateActor<Buddi_Base::Actor>();

		_actorToBeDestroyed = newScene.lock()->CreateActor<Buddi_Base::Actor>();
		_actorToBeDestroyed.lock()->SetTexture("C:\\Users\\heinp\\Documents\\2023_ACEDEMIC_YEAR\\ENGINE\\Buddi\\Buddi_Test_Game\\assets\\SpaceShooterRedux\\PNG\\playerShip1_blue.png");

		counter = 0;
	}

	void GameApplication::Update(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!_actorToBeDestroyed.expired())
			{
				_actorToBeDestroyed.lock()->Destroy();
			}
		}
	}
}