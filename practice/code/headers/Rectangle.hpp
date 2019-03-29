#pragma once

#include "Entity.hpp"

namespace example
{
	class Rectangle :public Entity
	{
	protected:
		float angle_in_rad;
	public:

		Rectangle(Scene * scene, float x, float y, float hx, float hy,  float angle = 0.f, b2BodyType type = b2_staticBody);

	public:
		void update(float deltaTime) override;

	public:
		void collision_enter() override;
		void collision_exit() override;
	};
}
