#pragma once

#include "Rectangle.hpp"

namespace example
{
	class Platform : public Rectangle
	{
	private:
		b2Vec2 target;
		b2Vec2 mov_vec;

		bool have_to_move;
		bool stopped;
		float angle_in_rad;

		float speed;

	public:
		Platform(Scene * scene, float x, float y, float hx, float hy, b2Vec2 offset, float speed, float angle = 0.f);

	public:
		void update(float deltaTime) override;

		void set_have_to_move(bool b);
		bool is_stopped() const { return stopped; }

	private:
		void move_to_target(float deltaTime);
		void move_to_init(float deltaTime);

		bool near_equals(b2Vec2 vec1, b2Vec2 vec2, float tolerance);
		b2Vec2 normalize(b2Vec2 v);

		int suma(int a, int b);
	};
}
