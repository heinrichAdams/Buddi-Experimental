#ifndef OBJECT_H
#define OBJECT_H

namespace Buddi_Base
{
	class Object
	{
	public: 
		Object();
		virtual ~Object();

		void Destroy();
		bool WaitingToDestroy() const { return _waitingToDestroy; }

	private:
		bool _waitingToDestroy;

	};
}

#endif