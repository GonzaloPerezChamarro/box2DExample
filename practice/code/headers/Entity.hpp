/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Base class of an entity or gameobject
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <map>
#include <string>

#include "Scene.hpp"

namespace example
{

	using namespace std;

	class Scene;

	class Entity
	{
	public:
		/* Constructor */
		Entity(Scene* scene);

		/* Destructor */
		virtual ~Entity();

		virtual void update(float deltaTime) = 0;

		virtual void render(sf::RenderWindow & renderer);

		virtual void reset() {}
		
		virtual void collision_enter(Entity*) = 0;
		virtual void collision_exit(Entity*) = 0;

		/* Returns the entity position */
		const b2Vec2& get_position() const { return bodies.at("rectangle")->GetPosition(); }
		void set_color(const sf::Color c) { color = c; }
		void set_enabled(bool b) { enabled = b; }
		void set_tag(std::string t) { tag = t; }
		std::string get_tag() const { return tag; }
		Scene* get_scene() const { return scene; }

	protected:
		/* Converts a b2Vec2 position vector to a sfml vector */
		sf::Vector2f convert_to_sfml_pos(const b2Vec2 & pos) const
		{
			float scale = scene->get_scale();
			const int windows_height = scene->get_height();
			return sf::Vector2f(pos.x * scale, (windows_height - pos.y) * scale);
		}

	protected:
		/* Map of bodies */
		map<string, b2Body*> bodies;

		/* Map of joints */
		map<string, b2Joint*> joints;

		/* Pointer to game scene */
		Scene* scene;

		/* Position of the entity */
		b2Vec2 position;

		/* Bodies' color */
		sf::Color color;

		/* Flag that indicates if the flag is active */
		bool enabled = true;

		/* Entity tag */
		std::string tag = "none";
	};
}