#pragma once

#include <SFML/Graphics.hpp>


namespace example
{
	class Particle
	{
	protected:

		sf::Vector2f current_position;

		sf::Color initial_color;
		sf::Color current_color;
		
		float life_time;
		float current_life_time;
		sf::Vector2f direction;
		float speed;
		Particle() {}

	public:
		virtual bool update(float deltaTime) = 0;
		virtual void render(sf::RenderWindow & renderer) = 0;
		virtual void reset(sf::Vector2f pos) = 0;

	};
}
