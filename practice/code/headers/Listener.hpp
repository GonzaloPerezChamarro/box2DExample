#pragma once

#include "Box2D/Box2D.h"

#include <iostream>

namespace example
{
	class Listener : public b2ContactListener
	{
	public:
		Listener()
		{}

	private:

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}
