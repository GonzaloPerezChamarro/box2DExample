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
			: Entity(scene), particles(particles_count), position(pos), initial_particles(particles_count), emission_rate(emission_rate), current_time(0.f)
		{

		}

		/**
		 * @brief Destructor de Particle_System
		 * 
		 */
		~Particle_System()
		{}


		void collision_enter() {}
		void collision_exit() {}

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
					p->reset(sf::Vector2f(position.x + 0, position.y + 0));
				current_time = 0.f;
			}
		}

	};

}
