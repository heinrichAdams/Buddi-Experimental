#include "Framework/Scene.h"
#include "Framework/Core.h"

namespace Buddi_Base
{
	Scene::Scene(Application* owner)
		: _owner{ owner },
		  _sceneStart{false}
	{

	}

	Scene::~Scene()
	{
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
