/**
 * @file ParticleSystem.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a simple particle system (templated)
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Entity.hpp"
#include "Pool.hpp"

#include <iostream>

namespace example
{
	template <class PARTICLE>
	class Particle_System : public Entity
	{
	public:
		/* Removed constructor by default */
		Particle_System() = delete;

		/* Constructor */
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

		/* Destructor*/
		~Particle_System()
		{}

		/* Called when an entity collides with the particle system */
		void collision_enter(Entity* e) override 
		{
			if (e->get_tag() == "ball")
			{
				scene->set_have_to_reset(true);
			}
		}

		/* Called when the collision with an entity ends */
		void collision_exit(Entity* e) override {}

		/**
		 * @brief Updates the state and emission
		 * @param deltaTime Delta time
		 */
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

		/**
		 * @brief Render the particle system
		 * @param renderer 
		 */
		void render(sf::RenderWindow & renderer) override
		{
			Entity::render(renderer);
			
			for (auto & particle : particles)
			{
				Part & p = particle;
				p.render(renderer);
			}
		}

	private:
		/**
		 * @brief Manages the particles emission
		 * @param deltaTime Delta time
		 */
		void emission(float deltaTime)
		{
			current_time += deltaTime;

			if (current_time >= emission_rate)
			{
				Part * p = particles.get_free_object();
				if(p)
					p->reset(sf::Vector2f(615, 625));

				current_time = 0.f;
			}
		}

	private:
		typedef PARTICLE Part;

		/* Pool of particles */
		Pool<PARTICLE> particles;

		/* Number of initial particles */
		size_t initial_particles;

		/* Position of particle system*/
		b2Vec2 position;

		/* Emission time rate */
		float emission_rate;

		/* Emission elapsed time */
		float current_time;
	};
}
