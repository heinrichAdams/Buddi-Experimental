#include "Framework/Actor.h"
#include "Framework/Core.h"

namespace Buddi_Base
{
	Actor::Actor(Scene* ownerScene, const std::string& path)
		: _ownerScene{ownerScene},
		  _started{false},
		  _sprite{},
		  _texture{}
	{
		SetTexture(path);
	}

	Actor::~Actor()
	{
		LOG("<--- Actor Destroyed --->");
	}

	void Actor::SetTexture(const std::string& path)
	{
		_texture.loadFromFile(path);
		_sprite.setTexture(_texture);

		int textureWidth = _texture.getSize().x;
		int textureHeight = _texture.getSize().y;
		_sprite.setTextureRect(sf::IntRect{ sf::Vector2i{},
			sf::Vector2i{textureWidth, textureHeight} });
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (!WaitingToDestroy())
		{
			window.draw(_sprite);
		}
	}

	void Actor::InternalAtStart()
	{
		if (!_started)
		{
			_started = true;
			AtStart();
		}
	}

	void Actor::AtStart()
	{
		LOG("Actor Initialized");
	}

	void Actor::InternalUpdate(float deltaTime)
	{
		if (!WaitingToDestroy())
		{
			Update(deltaTime);
		}
	}

	void Actor::Update(float deltaTime)
	{
		LOG("Actor Updated");
	}
}