/**
 * @file Rectangle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a rectangle with Box2D physics
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
	class Rectangle :public Entity
	{
	protected:
		float angle_in_rad;
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param x Position x
		 * @param y Position y
		 * @param hx Width
		 * @param hy Height
		 * @param angle Rotation angle
		 * @param type Body type
		 */
		Rectangle(Scene * scene, float x, float y, float hx, float hy,  float angle = 0.f, b2BodyType type = b2_staticBody);

	public:
		void update(float deltaTime) override;

	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;
	};
}
