#include <SFML/Graphics.hpp>
#include "Framework/Scene.h"
#include "Framework/Core.h"
#include "Framework/Actor.h"

namespace Buddi_Base
{
	Scene::Scene(Application* owner)
		: _owner{ owner },
		  _sceneStart{false},
		  _allActors{},
		  _pendingActors{}
	{

	}

	Scene::~Scene()
	{
	}

	void Scene::Render(sf::RenderWindow& window)
	{
		for (auto& actor : _allActors)
		{
			actor->Render(window);
		}
	}

	void Scene::InternalSceneStart()
	{
		if (!_sceneStart)
		{
			_sceneStart = true;
			SceneStart();
		}
	}

	void Scene::InternalUpdate(float deltaTime)
	{
		for (shared<Actor> actor : _pendingActors)
		{
			_allActors.push_back(actor);
			actor->InternalAtStart();
		}
		_pendingActors.clear();

		for (auto i = _allActors.begin(); i != _allActors.end(); )
		{
			if (i->get()->WaitingToDestroy())
			{
				i = _allActors.erase(i);
			}
			else
			{
				i->get()->Update(deltaTime);
				++i;
			}
		}

		Update(deltaTime);
	}

	void Scene::SceneStart()
	{
		LOG("<---Scene Started--->");
	}

	void Scene::Update(float deltaTime)
	{
		LOG("Scene Updated\nFPS: %f", 1.f/deltaTime);
	}

}
