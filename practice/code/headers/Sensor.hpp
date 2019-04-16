/**
 * @file Sensor.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Sensor (trigger) que al entrar en colision hace mover una plataforma (Platform)
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Platform.hpp"
#include "Scene.hpp"

#include "Vehicle.hpp"

namespace example
{
	class Sensor :public Rectangle
	{
	protected:

		/**
		 * @brief Puntero a la plataforma
		 * 
		 */
		Platform * platform;

		/**
		 * @brief Offset de la plataforma
		 * 
		 */
		b2Vec2 offset;

		/**
		 * @brief Tiempo de espera entre la entrada de la colision y el movimiento
		 * 
		 */
		float delay;

		/**
		 * @brief Tiempo actual esperado
		 * 
		 */
		float current_time;

		/**
		 * @brief Indica si el siguiente movimiento es hacia el target
		 * 
		 */
		bool next_mov;


	public:
		/**
		 * @brief Constructor de Sensor
		 * 
		 * @param scene Puntero a la escena
		 * @param x_pltf posicion del sensor
		 * @param y_pltf posicion del sensor
		 * @param hx ancho
		 * @param hy alto
		 * @param platform_name nombre de la entidad de la plataforma
		 * @param angle angulo de rotacion
		 */
		Sensor(Scene * scene, float x_pltf, float y_pltf, float hx, float hy, std::string platform_name, float angle = 0.f);
	
	public:
		void update(float deltaTime) override;

	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;


	};
}
