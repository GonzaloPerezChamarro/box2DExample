

#include "Particle.hpp"
#include "ParticleSystem.hpp"

namespace example
{
	Particle::Particle(Particle_System* system, Scene * scene, b2Vec2 pos, sf::Vector2f dir, float speed, float life_time, sf::Color c)
		:Entity(scene)
	{
		float pixels_scaled = scene->scale_pixels_to_sfml();

		current_radius = init_radius = 10.f;

		position.x = pos.x * pixels_scaled;
		position.y = pos.y * pixels_scaled;
		current_position.x = position.x;
		current_position.y = position.y;

		current_life_time = this->life_time = life_time;
		direction = dir;
		this->speed = speed;

		shape.setPosition(current_position);
		shape.setFillColor(color);
		shape.setRadius(init_radius);
		
		own_system = system;
	}

	void Particle::update(float deltaTime)
	{
		current_position += direction * speed * deltaTime;

		current_life_time -= deltaTime;

		if (current_life_time <= 0.f)
			own_system->kill_particle(this);

	}
	void Particle::reset_particle()
	{
		current_life_time = life_time;
		current_radius = init_radius;
		current_color = initial_color;
	}

	void Particle::collision_enter() {}
	void Particle::collision_exit() {}
}