/**
 * @file Hook.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa a un gancho
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
	class Hook :public Entity
	{
	private:

		/**
		 * @brief Prismatic joint que permite subir y bajar el gancho
		 * 
		 */
		b2PrismaticJoint * prim_joint;

		/**
		 * @brief Puntero al cuerpo principal 
		 * 
		 */
		b2Body * main_body;

		/**
		 * @brief Joint izquierdo de la garra
		 * 
		 */
		b2RevoluteJoint * joint_left;

		/**
		 * @brief Joint derecho de la garra
		 * 
		 */
		b2RevoluteJoint * joint_right;

		/**
		 * @brief Indica el estado del gancho
		 * 
		 */
		bool up;

	public:
		/**
		 * @brief Constructor de Hook
		 * 
		 * @param scene 
		 * @param x Posicion X
		 * @param y Posicion Y
		 */
		Hook(Scene * scene, float x, float y);

	public:
		/**
		 * @brief Actualiza el estado y gestiona el movimiento
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override;

	public:
		void collision_enter(Entity*) override {};
		void collision_exit(Entity*) override {};
	};
}