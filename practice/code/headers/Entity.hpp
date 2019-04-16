/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase base de una entidad o gameobject
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
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
	protected:
		
		/**
		 * @brief Mapa de b2Body de la entidad
		 * 
		 */
		map<string, b2Body*> bodies;

		/**
		 * @brief Mapa de joints de la entidad
		 * 
		 */
		map<string, b2Joint *> joints;

		/**
		 * @brief Puntero a la escena principal
		 * 
		 */
		Scene * scene;

		/**
		 * @brief Vector de posicion inicial
		 * 
		 */
		b2Vec2 position;

		/**
		 * @brief Color de los bodies de la entidad
		 * 
		 */
		sf::Color color;

		/**
		 * @brief Indica el estado de actividad de la entidad
		 * 
		 */
		bool enabled;
		std::string tag = "none";

	public:
		/**
		 * @brief Constructor de Entity
		 * 
		 * @param scene 
		 */
		Entity(Scene* scene);

		/**
		 * @brief Destructor de Entity
		 * 
		 */
		virtual ~Entity();



	public:
		/**
		 * @brief Metodo virtual puro llamado cada frame
		 * 
		 * @param deltaTime 
		 */
		virtual void update(float deltaTime) = 0;

		/**
		 * @brief Metodo de renderizado
		 * 
		 * @param renderer 
		 */
		virtual void render(sf::RenderWindow & renderer);

	public:

		/**
		 * @brief Devuelve puntero a la escena 
		 * 
		 * @return Scene* 
		 */
		Scene * get_scene() const
		{
			return scene;
		}
		
		/**
		 * @brief Metodo virtual puro llamado al entrar en colision
		 * 
		 */
		virtual void collision_enter(Entity*) = 0;
		/**
		 * @brief Metodo virtual puro llamado al salir de una colision
		 * 
		 */
		virtual void collision_exit(Entity*) = 0;

		virtual void reset() {}

		/**
		 * @brief Modifica el valor de color 
		 * 
		 * @param c 
		 */
		void set_color(const sf::Color c) { color = c; }

		/**
		 * @brief Devuelve position 
		 * 
		 * @return const b2Vec2& 
		 */
		const b2Vec2 & get_position() const
		{
			return bodies.at("rectangle")->GetPosition();
		}

		/**
		 * @brief Modifica el valor de enabled 
		 * 
		 * @param b 
		 */
		void set_enabled(bool b) { enabled = b; }
		void set_tag(std::string t) { tag = t; }
		std::string get_tag() const { return tag; }

	protected:

		/**
		 * @brief Convierte la posicion recibida a posicion de sfml
		 * 
		 * @param pos Vector de posicion
		 * @param windows_height altura de la ventana
		 * @return sf::Vector2f 
		 */
		sf::Vector2f convert_to_sfml_pos(const b2Vec2 & pos, float windows_height)
		{
			float scale = scene->get_scale();
			return sf::Vector2f(pos.x * scale, (windows_height - pos.y) * scale);
		}


	};
}