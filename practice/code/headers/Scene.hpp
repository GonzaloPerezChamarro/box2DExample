/**
 * @file Scene.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa una escena
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
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

	private:

		/**
		 * @brief Mapa de entidades
		 * 
		 */
		map<string, sh_Entity> entities_map;

		/**
		 * @brief Ancho de la ventana
		 * 
		 */
		int width;

		/**
		 * @brief Alto de la ventana
		 * 
		 */
		int height;

		/**
		 * @brief Factor de escala
		 * 
		 */
		float scale;

		/**
		 * @brief Gravedad
		 * 
		 */
		float gravity;

		/**
		 * @brief Mundo fisico
		 * 
		 */
		b2World world;
		Game * game;

		bool have_to_reset;

	public:
	/**
	 * @brief Constructor de Scene
	 * 
	 * @param width 
	 * @param height 
	 * @param scale 
	 * @param gravity 
	 */
		Scene(int width, int height, float scale, float gravity);
		virtual ~Scene();

	public:
		void update(float deltaTime);

		void render(sf::RenderWindow & renderer);

	public:

	//Metodos con nombres auto explicativos

		b2World & get_world() {return world;}

		int get_width() {return width;}

		int get_height() {return height;}

		float get_scale() const {return scale;}

		float get_gravity() const {return gravity;}

		float scale_pixels_to_sfml(){return 1.f / scale;}

		void set_game(Game * g) { game = g; }
		Game * get_game() const { return game; }

		void set_have_to_reset(bool b) { have_to_reset = b; }


		void add_entity(const std::string name, const sh_Entity & entity);

		Entity * get_entity_by_name(const std::string & name);

		void set_particle_system(Scene * scene, sf::Vector2i position, sf::Vector2f direction, size_t num_Particles);

	private:
		void reset();


	};
}
