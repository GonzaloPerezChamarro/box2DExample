/**
 * @file Circle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a circle with Box2D physics
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Entity.hpp"

namespace example
{
	class Circle : public Entity
	{
	public:
		/**
		 * @brief Constructor de Circle
		 * @param x Position X
		 * @param y Position Y
		 * @param radius of the circle
		 * @param scene Pointer to game scene
		 */
		Circle(float x, float y, float radius, Scene * scene);

	public:
		void update(float deltaTime) override;
		
	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

		void reset() override;
	};
}
