/**
 * @file Rectangle.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase base de un rectangulo con fisicas Box2D
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
	class Rectangle :public Entity
	{
	protected:
		float angle_in_rad;
	public:
		/**
		 * @brief Constructor de Rectangle
		 * 
		 * @param scene 
		 * @param x Posicion x
		 * @param y Posicion y
		 * @param hx ancho
		 * @param hy alto
		 * @param angle angulo de rotacion
		 * @param type tipo
		 */
		Rectangle(Scene * scene, float x, float y, float hx, float hy,  float angle = 0.f, b2BodyType type = b2_staticBody);

	public:
		void update(float deltaTime) override;

	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;
	};
}
