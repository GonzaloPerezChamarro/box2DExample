#pragma once

#include "Entity.hpp"
#include "Particle.hpp"
#include "Pool.hpp"

namespace example
{
	template <class PARTICLE>
	class Particle_System :public Entity
	{
		//static_assert(std::is_base_of<Particle, PARTICLE>, "FATHER ERROR");

	private:

		typedef PARTICLE Particle;

		Pool<Particle> particles;

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

		void update(float deltaTime);

		void render(sf::RenderWindow & renderer);

	private:
		void emission(float deltaTime);

	};

}
