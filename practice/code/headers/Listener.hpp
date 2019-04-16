/**
 * @file Listener.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Listener de eventos de colision
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
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
		/**
		 * @brief Constructor de Listener
		 * 
		 */
		Listener()
		{}

	private:

		/**
		 * @brief Entrada en contacto de dos fixtures
		 * 
		 * @param contact 
		 */
		void BeginContact(b2Contact* contact) override;

		/**
		 * @brief Perdida de contacto entre dos fixtures
		 * 
		 * @param contact 
		 */
		void EndContact(b2Contact* contact) override;
	};
}
