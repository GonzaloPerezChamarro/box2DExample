/**
 * @file Platform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Plataforma que se mueve entre dos posiciones
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Rectangle.hpp"

namespace example
{
	class Platform : public Rectangle
	{
	private:
		/**
		 * @brief Posicion target
		 * 
		 */
		b2Vec2 target;

		/**
		 * @brief Vector de movimiento
		 * 
		 */
		b2Vec2 mov_vec;

		/**
		 * @brief Indica si se tiene que mover al objetivo
		 * 
		 */
		bool have_to_move;

		/**
		 * @brief Indica si la plataforma esta parada
		 * 
		 */
		bool stopped;

		/**
		 * @brief Angulo en radianes
		 * 
		 */
		float angle_in_rad;

		/**
		 * @brief Velocidad de movimieto
		 * 
		 */
		float speed;

	public:
	/**
	 * @brief Constructor de Platform
	 * 
	 * @param scene 
	 * @param x posicion x
	 * @param y posicion y
	 * @param hx ancho
	 * @param hy largo
	 * @param offset target
	 * @param speed velocidad
	 * @param angle angulo
	 */
		Platform(Scene * scene, float x, float y, float hx, float hy, b2Vec2 offset, float speed, float angle = 0.f);

	public:
		void update(float deltaTime) override;

	public:

		/**
		 * @brief Modifica el valor de have to move 
		 * 
		 * @param b 
		 */
		void set_have_to_move(bool b);

		/**
		 * @brief Devuelve si la plataforma esta parada
		 * 
		 * @return true 
		 * @return false 
		 */
		bool is_stopped() const { return stopped; }

	private:
		/**
		 * @brief Mueve la plataforma al objetivo
		 * 
		 * @param deltaTime 
		 */
		void move_to_target(float deltaTime);

		/**
		 * @brief Mueve la plataforma a su posicion inicial
		 * 
		 * @param deltaTime 
		 */
		void move_to_init(float deltaTime);

		/**
		 * @brief Metodo que comprueba si dos vectores son iguales con cierta tolerancia
		 * 
		 * @param vec1 
		 * @param vec2 
		 * @param tolerance 
		 * @return true 
		 * @return false 
		 */
		bool near_equals(b2Vec2 vec1, b2Vec2 vec2, float tolerance);

		/**
		 * @brief Normalizacion de un vector
		 * 
		 * @param v 
		 * @return b2Vec2 
		 */
		b2Vec2 normalize(b2Vec2 v);
	};
}
