

#include "Rectangle.hpp"
#include "Platform.hpp"

#include <stdlib.h> 
#include <iostream>

namespace example
{
	Platform::Platform(Scene * scene, float x, float y, float hx, float hy, b2Vec2 target, float speed, float angle)
		:Rectangle(scene, x,y,hx,hy,angle, b2_kinematicBody)
	{
		angle_in_rad = angle * 3.1415f / 180;

		target_position.x = target.x * scene->scale_pixels_to_sfml();
		target_position.y = target.y * scene->scale_pixels_to_sfml();
		mov_vec = normalize(target_position - position);

		mov_speed = speed;
		moving_to_target = false;
		stopped = true;

		set_color(sf::Color::Green);
	}

	void Platform::update(float deltaTime)
	{
		if (stopped) return;

		if (moving_to_target)
			move_to_target(deltaTime);
		else
			move_to_init(deltaTime);
	}

	void Platform::set_move_to_target(bool b)
	{
		moving_to_target = b;
		stopped = false;
	}

	void Platform::move_to_target(float deltaTime)
	{
		if (!near_equals(bodies["rectangle"]->GetPosition(), target_position, 1.f))
		{
			bodies["rectangle"]->SetTransform(bodies["rectangle"]->GetPosition() +
				b2Vec2(mov_vec.x * mov_speed * deltaTime,
					mov_vec.y * mov_speed * deltaTime),
				angle_in_rad);
		}
		else
		{
			bodies["rectangle"]->SetTransform(target_position, angle_in_rad);
			stopped = true;
		}
	}

	void Platform::move_to_init(float deltaTime)
	{
		if (!near_equals(bodies["rectangle"]->GetPosition(), position, 1.f))
		{
			bodies["rectangle"]->SetTransform(bodies["rectangle"]->GetPosition() +
								b2Vec2(-mov_vec.x * mov_speed * deltaTime,-mov_vec.y * mov_speed * deltaTime),
								angle_in_rad);
		}
		else
		{
			bodies["rectangle"]->SetTransform(position, angle_in_rad);
			stopped = true;
		}
	}

	bool Platform::near_equals(b2Vec2 vec1, b2Vec2 vec2, float tolerance) const
	{
		float offset = abs(vec1.x - vec2.x) + abs(vec1.y - vec2.y);
		return offset < tolerance;
	}

	b2Vec2 Platform::normalize(b2Vec2 v) const
	{
		float mod = sqrt((v.x *  v.x + v.y * v.y));
		b2Vec2 vec{ v.x / mod, v.y / mod };
		return vec;
	}
}