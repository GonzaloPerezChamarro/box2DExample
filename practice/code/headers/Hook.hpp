#pragma once


#include "Entity.hpp"

namespace example
{
	class Hook :public Entity
	{
	private:

	public:
		Hook(Scene * scene, float x, float y);

	public:
		void update(float deltaTime) override;

	public:
		void collision_enter() override {};
		void collision_exit() override {};
	};
}