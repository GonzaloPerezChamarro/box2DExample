#pragma once

#include "Particle.hpp"
#include "Pool.hpp"

namespace example
{
	class Particle_System
	{
	private:
		size_t initial_particles;

		b2Vec2 position;
		sf::Vector2f direction;

		Pool * particles_pool;


	public:
		Particle_System() = delete;
		Particle_System(Scene * scene, b2Vec2 pos, sf::Vector2f dir,float speed, float life_time, size_t particles_count, float emission_time);

		~Particle_System();


		void update(float deltaTime);

		void render(sf::RenderWindow & renderer);

		void kill_particle(Particle * p);
	};
}
