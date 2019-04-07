#pragma once

#include "Entity.hpp"
#include "Pool.hpp"

namespace example
{
	class Particle;

	template <class PARTICLE>
	class Particle_System :public Entity
	{

	private:

		typedef PARTICLE Part;

		Pool<PARTICLE> particles;

		size_t initial_particles;

		b2Vec2 position;
		float emission_rate;

		float current_time;


	public:
		Particle_System() = delete;
		Particle_System(Scene * scene, b2Vec2 pos, size_t particles_count, float emission_rate);

		~Particle_System();

		// ÁREA
		// POSICIÓN


		void collision_enter() {}
		void collision_exit() {}

		void update(float deltaTime) override;

		void render(sf::RenderWindow & renderer) override;

	private:
		void emission(float deltaTime);

	};

}
