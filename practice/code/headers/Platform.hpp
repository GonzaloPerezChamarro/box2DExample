/**
 * @file Platform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Plataform that moves between two positions
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Rectangle.hpp"

namespace example
{
	class Platform : public Rectangle
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param x position x
		 * @param y position y
		 * @param hx Width
		 * @param hy height
		 * @param offset to target position
		 * @param speed Movement speed
		 * @param angle Angle
		 */
		Platform(Scene * scene, float x, float y, float hx, float hy, b2Vec2 offset, float speed, float angle = 0.f);

	public:
		void update(float deltaTime) override;

		/* Modifies if the platform has to move */
		void set_move_to_target(bool b);

		/* Returns if the platform is moving to target (or has arrived) */
		bool get_move_to_target() const { return moving_to_target; }

		/* Returns if the platform is stopped */
		bool is_stopped() const { return stopped; }

	private:
		/* Moves the platform to the target */
		void move_to_target(float deltaTime);

		/* Moves the platform to the initial position */
		void move_to_init(float deltaTime);

		/* Checks if two vectors are equals with a tolerance */
		bool near_equals(b2Vec2 vec1, b2Vec2 vec2, float tolerance) const;

		/* Normalize a vector */
		b2Vec2 normalize(b2Vec2 v) const;

	private:
		/* Target position */
		b2Vec2 target_position;

		/* Movement vector */
		b2Vec2 mov_vec;

		/* Flag that indicates if the platform has to move */
		bool moving_to_target;

		/* Flag that indicates if the platform is stopped */
		bool stopped;

		/* Angle in radians */
		float angle_in_rad;

		/* Movement speed */
		float mov_speed;
	};
}
