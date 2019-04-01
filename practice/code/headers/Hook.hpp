#pragma once


#include "Entity.hpp"

namespace example
{
	class Hook :public Entity
	{
	private:

		b2PrismaticJoint * prim_joint;
		b2Body * main_body;

		b2RevoluteJoint * joint_left;
		b2RevoluteJoint * joint_right;

		bool up;

	public:
		Hook(Scene * scene, float x, float y);

	public:
		void update(float deltaTime) override;

	public:
		void collision_enter() override {};
		void collision_exit() override {};
	};
}