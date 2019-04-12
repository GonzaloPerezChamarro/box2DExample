#pragma once

#include "Entity.hpp"

namespace example
{
	class Vehicle :public Entity
	{
	private:

		b2RevoluteJoint * wheel1;
		b2RevoluteJoint * wheel2;

		b2Vec2 wheel1_pos;
		b2Vec2 wheel2_pos;

		bool right;
		bool left;

		float motor_speed = 1100;

	public:

		Vehicle(Scene * scene, float x, float y);

	public:
		void update(float deltaTime) override;
		void reset() override;

	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

		void set_motor_speed(float new_speed) { motor_speed = new_speed; }

	private:
		void input();
	};
}