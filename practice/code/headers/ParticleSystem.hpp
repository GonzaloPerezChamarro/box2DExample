#pragma once

#include "Entity.hpp"
#include "Pool.hpp"

namespace example
{

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
		Particle_System(Scene * scene, b2Vec2 pos, size_t particles_count, float emission_rate)
			: Entity(scene), particles(particles_count), position(pos), initial_particles(particles_count), emission_rate(emission_rate), current_time(0.f)
		{

		}

		~Particle_System()
		{}

		// ÁREA
		// POSICIÓN


		void collision_enter() {}
		void collision_exit() {}

		void update(float deltaTime) override
		{
			for (auto & particle : particles)
			{
				Part & p = particle;
				if (!p.update(deltaTime))
				{
					particles.free_object(&p);
				}
			}
		}

		void render(sf::RenderWindow & renderer) override
		{

			for (auto & particle : particles)
			{
				Part & p = particle;
				p.render(renderer);
			}
		}

	private:
		void emission(float deltaTime)
		{
			current_time += deltaTime;

			if (current_time >= emission_rate)
			{
				Part * p = particles.get_free_object();
				p->reset(sf::Vector2f(100.f, 100.f));
			}
		}

	};

}
