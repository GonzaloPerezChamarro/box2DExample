/**
 * @file Listener.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Listener of collision events
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Box2D/Box2D.h"

#include <iostream>

namespace example
{
	class Listener : public b2ContactListener
	{
	public:
		/* Constructor */
		Listener()
		{}

	private:

		/* Called when entered on contact with other collision */
		void BeginContact(b2Contact* contact) override;

		/* Called when the contact with other collision ended */
		void EndContact(b2Contact* contact) override;
	};
}
