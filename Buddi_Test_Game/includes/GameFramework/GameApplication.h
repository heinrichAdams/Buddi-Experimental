#ifndef GAME_APP
#define GAME_APP

#include <Framework/Application.h>
#include <Framework/Actor.h>
#include <Framework/Core.h>

namespace Game
{
	class GameApplication : public Buddi_Base::Application
	{
	public:
		GameApplication();
		virtual void Update(float deltaTime) override;

	private:
		float counter;
		Buddi_Base::weak<Buddi_Base::Actor> _actorToBeDestroyed;

	};
}

#endif