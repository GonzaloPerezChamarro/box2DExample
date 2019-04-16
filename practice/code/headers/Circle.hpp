/**
 * @file Circle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase correspondiente a un circulo con fisicas Box2D
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Entity.hpp"

namespace example
{
	class Circle : public Entity
	{
	private:



	public:
	/**
	 * @brief Constructor de Circle
	 * 
	 * @param x Posicion X
	 * @param y Posicion Y
	 * @param radius Radio
	 * @param scene Puntero a escena
	 */
		Circle(float x, float y, float radius, Scene * scene);

	public:
		void update(float deltaTime) override;
		
	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

		void reset() override;

	};
}
