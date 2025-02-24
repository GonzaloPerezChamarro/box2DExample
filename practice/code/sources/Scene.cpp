

#include "Scene.hpp"
#include "Entity.hpp"
#include "Game.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Listener.hpp"
#include "Platform.hpp"
#include "Vehicle.hpp"
#include "Sensor.hpp"
#include "Hook.hpp"
#include "FireParticle.hpp"
#include "ParticleSystem.hpp"

namespace example
{
	Scene::Scene(int width, int height, float scale, float gravity)
		:width(int(width/scale)), height(int(height/scale)), scale(scale),
		gravity(gravity), world(b2Vec2(0.0f, -gravity)), game(nullptr)
	{
		have_to_reset = false;
	}

	Scene::~Scene()
	{
		entities_map.clear();

	}
	void Scene::update(float deltaTime)
	{
		for(auto iterator = entities_map.begin(), end = entities_map.end();
			iterator != end;
			++iterator)
		{
			iterator->second->update(deltaTime);
		}

		if (have_to_reset) reset();

		world.Step(deltaTime, 8,4);
	}

	void Scene::render(sf::RenderWindow & renderer)
	{
		for (auto iterator = entities_map.begin(), end = entities_map.end();
			iterator != end;
			++iterator)
		{
			iterator->second->render(renderer);
		}
	}

	void Scene::reset()
	{
		if (game) game->reset(); 
		have_to_reset = false;
	}

	void Scene::generate_world()
	{
		// Ball
		add_entity("ball", sh_Entity(new Circle(95.f, 300.f, 17.f, this)));

		// Main floor
		add_entity("floor01", sh_Entity(new Rectangle(this, 55.f, 50.f, 110.f, 100.f)));
		add_entity("floor02", sh_Entity(new Rectangle(this, 210.f, -7.f, 121.f, 112.f, -30.f)));
		add_entity("floor03", sh_Entity(new Rectangle(this, 200.f, 20.f, 800.f, 40.f)));

		// Second floor
		add_entity("floor04", sh_Entity(new Rectangle(this, 500.f, 410.f, 100.f, 20.f)));
		add_entity("floor05", sh_Entity(new Rectangle(this, 672.f, 440.f, 80.f, 20.f, 25.f)));
		add_entity("floor06", sh_Entity(new Rectangle(this, 868.f, 475.f, 130.f, 20.f)));

		// V goal target
		auto floorV1 = sh_Entity(new Rectangle(this, 60.f, 520.f, 70.f, 15.f, -45.f));
		auto floorV2 = sh_Entity(new Rectangle(this, 140.f, 520.f, 70.f, 15.f, 45.f));
		floorV1->set_color(sf::Color::Magenta);
		floorV2->set_color(sf::Color::Magenta);
		add_entity("floor07", floorV1);
		add_entity("floor08", floorV2);

		// Dynamic platforms 
		add_entity("platform01", sh_Entity(new Platform(this, 1132.f, 40.f, 130.f, 20.f, b2Vec2(1132.f, 475.f), 10.f)));
		add_entity("platform02", sh_Entity(new Platform(this, 298, 410.f, 95.f, 20.f, b2Vec2(298, 565), 10.f)));

		// Sensors
		add_entity("sensor1", sh_Entity(new Sensor(this, 1142.f, 90.f, 110.f, 30.f, "platform01")));
		add_entity("sensor2", sh_Entity(new Sensor(this, 308, 465.f, 75.f, 30.f, "platform02")));

		// Vehicle
		add_entity("vehicle", sh_Entity(new Vehicle(this, 95.f, 230.f)));

		// Walls
		add_entity("left_wall", sh_Entity(new Rectangle(this, -5.f, 720.f * 0.5f, 10.f, 720.f)));
		add_entity("right_wall", sh_Entity(new Rectangle(this, 1280.f + 5.f, 720.f * 0.5f, 10.f, 720.f)));

		// Hook
		add_entity("hook", sh_Entity(new Hook(this, 600.f, 380.f)));

		// Fire
		add_entity("fire", sh_Entity(new Particle_System<Fire_Particle>(this, b2Vec2(630.f, 120.f), b2Vec2(0.f,0.f), 15, 0.4f)));
	}

	void Scene::add_entity(const std::string name, const sh_Entity& entity)
	{
		entities_map[name] = entity;
		entity->set_tag(name);
	}

	Entity* Scene::get_entity_by_name(const std::string & name) const
	{
		return entities_map.find(name)->second.get();
	}
}