#include "FireParticle.hpp"

#include <math.h>

namespace example
{
	Fire_Particle::Fire_Particle()
	{
		direction = sf::Vector2f(0.f, -1.f);
		speed = rand() % 12 + 20.f;
		color = sf::Color::Red;
		color = sf::Color(255, rand() % 120, rand() %100, rand() % 100 + 155);
		end_color = sf::Color::Yellow;
		delta_color = end_color - color;
		life_time = 1.8f;
		init_radius = rand() % 7 + 7.f;

		reset(sf::Vector2f(0, 0));
	}

	bool Fire_Particle::update(float deltaTime)
	{
		
		current_life_time -= deltaTime;


		current_position = current_position + direction * speed * deltaTime;
		shape.setPosition(current_position);

		current_radius = current_radius - 2.5f *deltaTime;
		shape.setRadius(current_radius);

		//Modifica el color, pero produce errores en ejecucion
		/*
		current_color = color + (sf::Color(delta_color.r * (current_life_time) ,
											delta_color.g * (current_life_time),
											delta_color.b * (current_life_time)));*/
		


		shape.setFillColor(current_color);
		return current_life_time > 0.f;
	}

	void Fire_Particle::render(sf::RenderWindow & renderer)
	{
		renderer.draw(shape);

	}

	void Fire_Particle::reset(sf::Vector2f pos)
	{
		current_position.y = pos.y + (rand() % 6) - 3.f;
		current_position.x = pos.x + (rand() % 10) - 5.f;
		current_life_time = life_time;
		init_radius = rand() % 7 + 7.f;
		current_radius = init_radius;
		current_color = color;
	}
}