/**
 * @file FireParticle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa una particula de fuego
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Particle.hpp"

namespace example
{
	class Fire_Particle :public Particle
	{

	private:
		/**
		 * @brief circulo de la particula
		 * 
		 */
		sf::CircleShape shape;

		/**
		 * @brief Radio inicial
		 * 
		 */
		float init_radius;

		/**
		 * @brief Radio actual de la particula
		 * 
		 */
		float current_radius;

		/**
		 * @brief Color de la particula inicial
		 * 
		 */
		sf::Color color;

		/**
		 * @brief Color actual
		 * 
		 */
		sf::Color current_color;

		/**
		 * @brief Color final
		 * 
		 */
		sf::Color end_color;

		/**
		 * @brief Color delta
		 * 
		 */
		sf::Color delta_color;

	public:
		/**
		 * @brief Constructor de Fire_Particle
		 * 
		 */
		Fire_Particle();

		/**
		 * @brief Modifica el eestado de la particula cada frame
		 * 
		 * @param deltaTime 
		 * @return true particula viva
		 * @return false particula muerta
		 */
		bool update(float deltaTime) override;

		/**
		 * @brief Renderiza la particula
		 * 
		 * @param renderer 
		 */
		void render(sf::RenderWindow & renderer) override;

		/**
		 * @brief Resetea los valores de la particula a los iniciales
		 * 
		 * @param pos 
		 */
		void reset(sf::Vector2f pos) override;


	};
}
