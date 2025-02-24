/**
 * @file Particle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Abstract class that represents a particle. Inherit from it to create new particles
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"

namespace example
{
	class Particle
	{
	public:
		virtual bool update(float deltaTime) = 0;
		virtual void render(sf::RenderWindow & renderer) = 0;
		virtual void reset(sf::Vector2f pos) = 0;

	protected:
		/* Constructor */
		Particle() : life_time(0.f), current_life_time(0.f), speed(0.f) {}

		/* Current position of the particle */
		sf::Vector2f current_position;

		/* Initial color */
		sf::Color initial_color;

		/* Current color */
		sf::Color current_color;
		
		/* Max life time of the particle */
		float life_time;

		/* Curent life time of the particle */
		float current_life_time;

		/* Movement direction */
		sf::Vector2f direction;

		/* Movement speed */
		float speed;
	};
}
