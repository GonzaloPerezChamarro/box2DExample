#include "FireParticle.hpp"

#include <cmath>

namespace example
{
	Fire_Particle::Fire_Particle()
	{
		direction = sf::Vector2f(0.f, -1.f);
		speed = rand() % 12 + 20.f;
		color = sf::Color(255, rand() % 120, rand() % 100, rand() % 100 + 155);
		end_color = sf::Color(240 + rand() % 10, 240 + rand() % 10, 34 + rand() % 10, 155 + rand() % 100);
		end_color = sf::Color::Yellow;
		life_time = 1.8f;
		init_radius = rand() % 7 + 7.f;

		reset(sf::Vector2f(0, 0));
	}

	bool Fire_Particle::update(float deltaTime)
	{
		current_life_time -= deltaTime;

		current_position = current_position + direction * speed * deltaTime;
		current_radius = current_radius - (2.5f * deltaTime);

		const float delta = 1 - current_life_time / life_time;
		current_color = sf::Color(std::lerp(color.r, end_color.r, delta), std::lerp(color.g, end_color.g, delta), std::lerp(color.b, end_color.b, delta));
		
		return current_life_time > 0.f;
	}

	void Fire_Particle::render(sf::RenderWindow & renderer)
	{
		shape.setPosition(current_position);
		shape.setRadius(current_radius);
		shape.setFillColor(current_color);

		renderer.draw(shape);
	}

	void Fire_Particle::reset(sf::Vector2f pos)
	{
		current_position = pos;
		current_life_time = life_time;
		init_radius = 10.f;
		current_radius = init_radius;
		current_color = color;
	}
}
