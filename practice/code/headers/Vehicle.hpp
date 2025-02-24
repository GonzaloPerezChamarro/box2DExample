/**
 * @file Vehicle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a vehicle with physics
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * s
 */

#pragma once

#include "Entity.hpp"

namespace example
{
	class Vehicle :public Entity
	{
	public:

		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param x Position x
		 * @param y Position y
		 */
		Vehicle(Scene * scene, float x, float y);

		void update(float deltaTime) override;
		void reset() override;

		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

		void set_motor_speed(float new_speed) { motor_speed = new_speed; }

	private:
		void input();

	private:

		b2RevoluteJoint* wheel1;
		b2RevoluteJoint* wheel2;

		/* WHeel 1 position */
		b2Vec2 wheel1_pos;

		/* Wheel 2 position */
		b2Vec2 wheel2_pos;

		/* Flag that indicates if it is moving to the right */
		bool right;

		/* Flag that indicates if it is moving to the left */
		bool left;

		/* Movement speed */
		float motor_speed = 1100;
	};
}