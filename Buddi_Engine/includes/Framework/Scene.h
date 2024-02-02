#ifndef SCENE_H
#define SCENE_H

namespace Buddi_Base
{
	class Application;
	class Scene
	{
	public:
		Scene(Application* owner);
		virtual ~Scene();

		void InternalSceneStart();
		void InternalUpdate(float deltaTime);

	private:
		void SceneStart();
		void Update(float deltaTime);

		Application* _owner;
		bool _sceneStart;

	};
}

#endif