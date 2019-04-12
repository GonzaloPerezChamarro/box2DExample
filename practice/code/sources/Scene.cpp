

#include "Scene.hpp"
#include "Entity.hpp"
#include "Game.hpp"

namespace example
{
	Scene::Scene(int width, int height, float scale, float gravity)
		:width(width/scale), height(height/scale), scale(scale),
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
		for(
			auto iterator = entities_map.begin(), end = entities_map.end();
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
		for (
			auto iterator = entities_map.begin(), end = entities_map.end();
			iterator != end;
			++iterator)
		{
			iterator->second->render(renderer);
		}
	}
	void Scene::add_entity(const std::string name, const sh_Entity & entity)
	{
		entities_map[name] = entity;
	}

	Entity * Scene::get_entity_by_name(const std::string & name)
	{
		return entities_map.find(name)->second.get();
	}

	void Scene::set_particle_system(Scene * scene, sf::Vector2i position, sf::Vector2f direction, size_t num_Particles)
	{
	}

	void Scene::reset()
	{
		if (game) game->reset(); 
		have_to_reset = false;
	}
}