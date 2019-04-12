#pragma once

#include "Entity.hpp"

namespace example
{
	class Circle : public Entity
	{
	private:



	public:
		Circle(float x, float y, float radius, Scene * scene);

	public:
		void update(float deltaTime) override;
		
	public:
		void collision_enter(Entity*) override;
		void collision_exit(Entity*) override;

		void reset() override;

	};
}
