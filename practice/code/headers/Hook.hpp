/**
 * @file Hook.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a hook
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
	class Hook :public Entity
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param x Position X
		 * @param y Position Y
		 */
		Hook(Scene * scene, float x, float y);

	public:
		/**
		 * @brief Updates the state and manages the movement
		 * @param deltaTime Delta time
		 */
		void update(float deltaTime) override;

		void collision_enter(Entity*) override {};
		void collision_exit(Entity*) override {};

	private:
		/* Prismatic joint that allows to move up and down the hook */
		b2PrismaticJoint* prim_joint;

		/* Pointer to main body */
		b2Body* main_body;

		/* Pointer to the left side of the hook */
		b2RevoluteJoint* joint_left;

		/* Pointer to the right side of the hook */

		b2RevoluteJoint* joint_right;

		/* Flag that indicates if the hook is up */
		bool up;
	};
}