/**
 * @file Sensor.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a sensor/trigger that activates a platform when collides with something
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Platform.hpp"
#include "Scene.hpp"
#include "Vehicle.hpp"

#include <set>

namespace example
{
	class Sensor :public Rectangle
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param x_pltf Position X
		 * @param y_pltf Position Y
		 * @param hx Width
		 * @param hy Height
		 * @param platform_name Name of the entity platform
		 * @param angle Rotation angle
		 */
		Sensor(Scene * scene, float x_pltf, float y_pltf, float hx, float hy, std::string platform_name, float angle = 0.f);

		void update(float deltaTime) override;

		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

	protected:
		/* Pointer to the platform */
		Platform* platform;

		/* Movement offset of the platform */
		b2Vec2 offset;

		/* Delay between collision and activation */
		float delay;

		/* Collision elapsed time */
		float current_time;

		/* Flag that indicates that a collision is detected */
		bool collision_detected;

		/* Array of entities detected by the trigger */
		std::set<std::string> entities_detected;
	};
}
