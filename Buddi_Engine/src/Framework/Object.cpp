#include "Framework/Object.h"
#include "Framework/Core.h"

namespace Buddi_Base
{
	Object::Object()
		: _waitingToDestroy{false}
	{

	}

	Object::~Object()
	{
		LOG("<--- Object Destroyed --->");
	}

	void Object::Destroy()
	{
		_waitingToDestroy = true;
	}
}