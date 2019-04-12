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
	protected:
		
		map<string, b2Body*> bodies;
		map<string, b2Joint *> joints;

		Scene * scene;

		b2Vec2 position;

		sf::Color color;

		bool enabled;
		std::string tag = "none";

	public:
		Entity(Scene* scene);
		virtual ~Entity();



	public:
		virtual void update(float deltaTime) = 0;
		virtual void render(sf::RenderWindow & renderer);

	public:

		Scene * get_scene() const
		{
			return scene;
		}
		
		virtual void collision_enter(Entity*) = 0;
		virtual void collision_exit(Entity*) = 0;

		virtual void reset() {}

		void set_color(const sf::Color c) { color = c; }

		const b2Vec2 & get_position() const
		{
			return bodies.at("rectangle")->GetPosition();
		}

		void set_enabled(bool b) { enabled = b; }
		void set_tag(std::string t) { tag = t; }
		std::string get_tag() const { return tag; }

	protected:

		sf::Vector2f convert_to_sfml_pos(const b2Vec2 & pos, float windows_height)
		{
			float scale = scene->get_scale();
			return sf::Vector2f(pos.x * scale, (windows_height - pos.y) * scale);
		}


	};
}