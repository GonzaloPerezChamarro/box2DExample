/**
 * @file FireParticle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a fire particle
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Particle.hpp"

namespace example
{
	class Fire_Particle : public Particle
	{

	private:
		/* Circle shape */
		sf::CircleShape shape;

		/* Initial radius */
		float init_radius;

		/* Current radius */
		float current_radius;

		/* Initial color */
		sf::Color color;

		/* Current color */
		sf::Color current_color;

		/* End color */
		sf::Color end_color;

		/* Delta color */
		sf::Color delta_color;

	public:
		/* Constructor */
		Fire_Particle();

		/**
		 * @brief Modifies the particle's state every tick
		 * @param deltaTime Delta time 
		 * @return true if the particle is alive
		 */
		bool update(float deltaTime) override;

		void render(sf::RenderWindow & renderer) override;
		void reset(sf::Vector2f pos) override;
	};
}
