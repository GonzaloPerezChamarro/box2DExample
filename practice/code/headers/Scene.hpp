/**
 * @file Scene.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a game scene
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <string>
#include <map>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>


namespace example
{
	using namespace std;

	class Entity;
	class Game;
	class Scene
	{
	private:
		typedef std::shared_ptr<Entity> sh_Entity;

	public:
		/* Constructor */
		Scene(int width, int height, float scale, float gravity);

		/* Destructor */
		virtual ~Scene();

	public:
		void update(float deltaTime);
		void render(sf::RenderWindow & renderer);

		void generate_world();

		b2World & get_world() { return world; }

		int get_width() const { return width; }

		int get_height() const { return height; }

		float get_scale() const { return scale; }

		float get_gravity() const { return gravity; }

		float scale_pixels_to_sfml() const { return 1.f / scale; }

		void set_game(Game * g) { game = g; }
		Game * get_game() const { return game; }

		void set_have_to_reset(bool b) { have_to_reset = b; }

		void add_entity(const std::string name, const sh_Entity & entity);

		Entity * get_entity_by_name(const std::string & name) const;

		void set_particle_system(Scene * scene, sf::Vector2i position, sf::Vector2f direction, size_t num_Particles);

	private:
		void reset();

	private:
		/* Entity map */
		map<string, sh_Entity> entities_map;

		/* Window's width */
		int width;

		/* Window's height */
		int height;

		/* Scale factor */
		float scale;

		/* Gravity */
		float gravity;

		/* Physical world */
		b2World world;

		/* Pointer to the game */
		Game* game;

		/* Flag indicates if the scene has to reset */
		bool have_to_reset;
	};
}
