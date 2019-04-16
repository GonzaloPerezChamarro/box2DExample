/**
 * @file Particle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase abstracta que representa a una particula. Se debe heredar de esta para crear nuevas particulas
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"

namespace example
{
	class Particle
	{
	protected:

		/**
		 * @brief Posicion actual de la particula
		 * 
		 */
		sf::Vector2f current_position;

		/**
		 * @brief Color inicial
		 * 
		 */
		sf::Color initial_color;

		/**
		 * @brief Color final
		 * 
		 */
		sf::Color current_color;
		
		/**
		 * @brief Tiempo de vida de la particula
		 * 
		 */
		float life_time;

		/**
		 * @brief Tiempo de vida actual
		 * 
		 */
		float current_life_time;

		/**
		 * @brief Vector de direccion de movimiento
		 * 
		 */
		sf::Vector2f direction;

		/**
		 * @brief Velocidad de la particula
		 * 
		 */
		float speed;

		/**
		 * @brief Constructor de Particle
		 * 
		 */
		Particle() {}

	public:
		virtual bool update(float deltaTime) = 0;
		virtual void render(sf::RenderWindow & renderer) = 0;
		virtual void reset(sf::Vector2f pos) = 0;

	
	};
}
