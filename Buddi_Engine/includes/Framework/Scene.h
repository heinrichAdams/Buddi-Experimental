#ifndef SCENE_H
#define SCENE_H

#include "Framework/Core.h"

namespace Buddi_Base
{
	class Actor;
	class Application;
	class Scene
	{
	public:
		Scene(Application* owner);
		virtual ~Scene();

		void Render(sf::RenderWindow& window);

		void InternalSceneStart();
		void InternalUpdate(float deltaTime);

		template<typename ActorType>
		weak<ActorType> CreateActor();

	private:
		void SceneStart();
		void Update(float deltaTime);

		Application* _owner;
		bool _sceneStart;

		List<shared<Actor>> _allActors;
		List<shared<Actor>> _pendingActors;
	};

	template<typename ActorType>
	weak<ActorType> Scene::CreateActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		_pendingActors.push_back(newActor);
		return newActor;
	}
}

#endif