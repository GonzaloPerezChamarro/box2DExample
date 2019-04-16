/**
 * @file ParticleSystem.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Sistema de particulas sencillo
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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

		/**
		 * @brief Pool de particulas
		 * 
		 */
		Pool<PARTICLE> particles;

		/**
		 * @brief Numero de particulas iniciales
		 * 
		 */
		size_t initial_particles;

		/**
		 * @brief Posicion del sistema de particulas
		 * 
		 */
		b2Vec2 position;

		/**
		 * @brief Tiempo de emision entre particulas
		 * 
		 */
		float emission_rate;

		/**
		 * @brief Tiempo actual
		 * 
		 */
		float current_time;


	public:
		Particle_System() = delete;

		/**
		 * @brief Constructor de Particle_System
		 * 
		 * @param scene Puntero a la escena
		 * @param pos Posicion
		 * @param particles_count Numero de particulas
		 * @param emission_rate Tiempo de emision
		 */
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

		/**
		 * @brief Destructor de Particle_System
		 * 
		 */
		~Particle_System()
		{}


		void collision_enter(Entity* e)override 
		{
			std::cout << e->get_tag() << std::endl;
			if (e->get_tag() == "ball")
			{
				scene->set_have_to_reset(true);
			}
		}
		void collision_exit(Entity* e) override{}

		/**
		 * @brief Actualizado de las particulas y su emision
		 * 
		 * @param deltaTime 
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
		 * @brief Renderizado de las particulas
		 * 
		 * @param renderer 
		 */
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

		/**
		 * @brief Emite particulas si es necesario
		 * 
		 * @param deltaTime 
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

	};

}
