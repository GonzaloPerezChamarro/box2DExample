#include "FireParticle.hpp"

namespace example
{
	Fire_Particle::Fire_Particle()
	{
		direction = sf::Vector2f(0.f, -1.f);
		speed = 20.f;
		color = sf::Color::Red;
		end_color = sf::Color::Yellow;
		delta_color = end_color - color;
		life_time = 2.f;
		init_radius = 10.f;

		reset(sf::Vector2f(0, 0));
	}

	bool Fire_Particle::update(float deltaTime)
	{
		
		current_life_time -= deltaTime;

		current_position = current_position + direction * speed * deltaTime;
		current_radius = current_radius - 2.f *deltaTime;
		shape.setRadius(current_radius);

		current_color = color + (sf::Color(delta_color.r * current_life_time ,
											delta_color.g * current_life_time,
											delta_color.b * current_life_time));
		
		shape.setPosition(current_position);
		shape.setFillColor(current_color);
		return current_life_time > 0.f;
	}

	void Fire_Particle::render(sf::RenderWindow & renderer)
	{
		renderer.draw(shape);

	}

	void Fire_Particle::reset(sf::Vector2f pos)
	{
		current_position = pos;
		current_life_time = life_time;
		shape.setRadius(init_radius);
		current_radius = init_radius;
		current_color = color;
	}
}