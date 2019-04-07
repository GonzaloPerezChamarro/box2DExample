

#include "Rectangle.hpp"
#include "Platform.hpp"

#include <stdlib.h> 
#include <iostream>

namespace example
{
	Platform::Platform(Scene * scene, float x, float y, float hx, float hy, b2Vec2 target, float speed, float angle)
		:Rectangle(scene, x,y,hx,hy,angle, b2_kinematicBody)
	{
		this->angle_in_rad = angle * 3.1415 / 180;

		this->target.x = target.x * scene->scale_pixels_to_sfml();
		this->target.y = target.y * scene->scale_pixels_to_sfml();
		mov_vec = normalize(this->target - position);

		this->speed = speed;
		have_to_move = false;
		stopped = true;

		set_color(sf::Color::Green);
	}

	void Platform::update(float deltaTime)
	{
		if (have_to_move)
			move_to_target(deltaTime);
		else
			move_to_init(deltaTime);
	}

	void Platform::set_have_to_move(bool b)
	{
		have_to_move = b;
		stopped = false;
	}

	void Platform::move_to_target(float deltaTime)
	{
		if (!near_equals(bodies["rectangle"]->GetPosition(), target, 0.1f))
		{
			bodies["rectangle"]->SetTransform(bodies["rectangle"]->GetPosition() +
				b2Vec2(mov_vec.x * speed * deltaTime,
					mov_vec.y * speed * deltaTime),
				angle_in_rad);
		}
		else if (!stopped)
		{

			bodies["rectangle"]->SetTransform(target, angle_in_rad);
			stopped = true;
		}
	}

	void Platform::move_to_init(float deltaTime)
	{
		if (!near_equals(bodies["rectangle"]->GetPosition(), position, 0.1f))
		{
			bodies["rectangle"]->SetTransform(bodies["rectangle"]->GetPosition() +
								b2Vec2(-mov_vec.x * speed * deltaTime,-mov_vec.y * speed * deltaTime),
								angle_in_rad);
		}
		else if (!stopped)
		{
			bodies["rectangle"]->SetTransform(position, angle_in_rad);
			stopped = true;
		}
	}

	bool Platform::near_equals(b2Vec2 vec1, b2Vec2 vec2, float tolerance)
	{
		float offset = abs(vec1.x - vec2.x) + abs(vec1.y - vec2.y);
		return offset < tolerance;
	}

	b2Vec2 Platform::normalize(b2Vec2 v)
	{
		float mod = sqrt((v.x *  v.x + v.y * v.y));
		b2Vec2 vec{ v.x / mod, v.y / mod };
		return vec;
	}


}