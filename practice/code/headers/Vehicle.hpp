/**
 * @file Vehicle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Vehiculo con movimiento y fisicas box2D
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * s
 */

#pragma once

#include "Entity.hpp"

namespace example
{
	class Vehicle :public Entity
	{
	private:

		/**
		 * @brief Rueda 1
		 * 
		 */
		b2RevoluteJoint * wheel1;

		/**
		 * @brief Rueda 2
		 * 
		 */
		b2RevoluteJoint * wheel2;

		/**
		 * @brief Posicion de la rueda 1
		 * 
		 */
		b2Vec2 wheel1_pos;

		/**
		 * @brief Posicion de la rueda 2
		 * 
		 */
		b2Vec2 wheel2_pos;

		/**
		 * @brief Indica si se esta moviendo a la derecha
		 * 
		 */
		bool right;

		/**
		 * @brief Indica si se esta moviendo a la izquierda
		 * 
		 */
		bool left;

		/**
		 * @brief Velocidad del motor
		 * 
		 */
		float motor_speed = 1100;

	public:

		/**
		 * @brief Constructor de Vehicle
		 * 
		 * @param scene 
		 * @param x Posicion x
		 * @param y Posicion y
		 */
		Vehicle(Scene * scene, float x, float y);

	public:
		/**
		 * @brief Modifica en caso necesario la velocidad del vehiculo
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override;

	public:
		void collision_enter() override;
		void collision_exit() override;

		void set_motor_speed(float new_speed) { motor_speed = new_speed; }

	private:
		/**
		 * @brief Input de teclado
		 * 
		 */
		void input();
	};
}