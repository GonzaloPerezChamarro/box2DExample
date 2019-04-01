

#include "ParticleSystem.hpp"

namespace example
{
	Particle_System::Particle_System(Scene * scene, b2Vec2 pos, sf::Vector2f dir,float speed, float life_time, size_t particles_count, float emission_time)
		:position(pos), direction(dir), initial_particles(particles_count)
	{
		Particle * particle = new Particle(this,scene, position,dir, speed, life_time, sf::Color::Red);
		particles_pool = new Pool(particle, initial_particles);
	}
	Particle_System::~Particle_System()
	{
		particles_pool->reset_pool();
	}

	void Particle_System::update(float deltaTime)
	{
		for (auto particle : particles_pool->get_active_entities())
		{
			particle->update(deltaTime);
		}
	}

	void Particle_System::render(sf::RenderWindow & renderer)
	{
		for (auto particle : particles_pool->get_active_entities())
		{
			renderer.draw(static_cast<Particle*>((particle).get())->get_shape());
		}
	}

	void Particle_System::kill_particle(Particle * p)
	{
		particles_pool->return_to_pool(p);
	}
}