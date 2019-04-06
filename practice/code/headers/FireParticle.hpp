#pragma once

#include "Particle.hpp"

namespace example
{
	class Fire_Particle :public Particle
	{

	private:
		sf::CircleShape shape;
		float init_radius;
		float current_radius;

	public:
		Fire_Particle();

		bool update(float deltaTime) override;

		void render(sf::RenderWindow & renderer) override;

		void reset() override;


	};
}
