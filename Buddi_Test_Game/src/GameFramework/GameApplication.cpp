#include "GameFramework/GameApplication.h"
#include "Framework/Scene.h"

Buddi_Base::Application* GetApplication()
{
	return new Game::GameApplication{};
}

namespace Game
{
	GameApplication::GameApplication()
	{
		Buddi_Base::Application::LoadScene<Buddi_Base::Scene>();
	}
}