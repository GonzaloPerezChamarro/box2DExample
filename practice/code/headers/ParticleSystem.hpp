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
			: Entity(scene), particles(particles_count), initial_particles(particles_count), emission_rate(emission_rate), current_time(0.f)
		{
			float pixels_scaled = scene->scale_pixels_to_sfml();


			b2BodyDef body;
			body.type = b2_staticBody;
			body.fixedRotation = false;

			position = pos;
			body.position.Set(position.x, position.y);
			body.userData = this;
			

			bodies["trigger"] = scene->get_world().CreateBody(&body);

			b2PolygonShape shape;
			b2FixtureDef fixture;
			shape.SetAsBox(23 * pixels_scaled,50 * pixels_scaled);
			fixture.shape = &shape;
			fixture.isSensor = true;

			bodies["trigger"]->CreateFixture(&fixture);
			set_color(sf::Color::Black);
		}

		~Particle_System()
		{}

		// ÁREA
		// POSICIÓN


		void collision_enter(Entity* e)override 
		{
			std::cout << e->get_tag() << std::endl;
			if (e->get_tag() == "ball")
			{
				scene->set_have_to_reset(true);
			}
		}
		void collision_exit(Entity* e) override{}

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
			emission(deltaTime);
		}

		void render(sf::RenderWindow & renderer) override
		{
			__super::render(renderer);
			
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
				if(p)
					p->reset(sf::Vector2f(615, 620));
				current_time = 0.f;
			}
		}

	};

}
