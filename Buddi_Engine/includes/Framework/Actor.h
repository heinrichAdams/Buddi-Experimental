#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include "Framework/Core.h"
#include "Framework/Object.h"

namespace Buddi_Base
{
	class Scene;
	class Actor : public Object
	{
	public:

		Actor(Scene* ownerScene, const std::string& path = "");
		virtual ~Actor();

		void SetTexture(const std::string& path = "");
		void Render(sf::RenderWindow& window);

		void InternalAtStart();
		virtual void AtStart();

		void InternalUpdate(float deltaTime);
		virtual void Update(float deltaTime);

	private:
		Scene* _ownerScene;
		bool _started;

		sf::Sprite _sprite;
		sf::Texture _texture;

	};
}

#endif
