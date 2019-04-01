#pragma once

#include "Entity.hpp"


namespace example
{
	class Particle_System;
	class Particle :public Entity
	{
	private:

		sf::Vector2f current_position;

		sf::CircleShape shape;
		float init_radius;
		float current_radius;
		sf::Color initial_color;
		sf::Color current_color;
		
		float life_time;
		float current_life_time;
		sf::Vector2f direction;
		float speed;

		Particle_System * own_system;


	public:
		Particle() = delete;
		Particle(Particle_System* system,Scene * scene, b2Vec2 position, sf::Vector2f dir,float speed, float life_time, sf::Color c);

	public:
		void update(float deltaTime) override;

		void collision_enter() override;
		void collision_exit() override;

	public: 
		void reset_particle();


		sf::CircleShape & get_shape() { return shape; }

	};
}
