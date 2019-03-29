#pragma once

#include "Platform.hpp"
#include "Scene.hpp"

#include "Vehicle.hpp"

namespace example
{
	class Sensor :public Rectangle
	{
	protected:

		Platform * platform;

		b2Vec2 offset;

		float delay;
		float current_time;
		bool next_mov;


	public:
		Sensor(Scene * scene, float x_pltf, float y_pltf, float hx, float hy, std::string platform_name, float angle = 0.f);
	
	public:
		void update(float deltaTime) override;

	public:
		void collision_enter() override;
		void collision_exit() override;


	};
}
