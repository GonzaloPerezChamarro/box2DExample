/**
 * @file Game.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de juego principal
 * @version 0.1
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include "Entity.hpp"

namespace example
{

	class Game
	{
	private:
		typedef std::shared_ptr<Entity> sh_Entity;

	private:
		/**
		 * @brief Ventana de juego
		 * 
		 */
		sf::RenderWindow window;

		/**
		 * @brief Puntero a la escena principal
		 * 
		 */
		Scene * scene;

	public:

		/**
		 * @brief Constructor de Game
		 * 
		 * @param window_name Nombre de la ventana
		 * @param width Ancho de la ventana
		 * @param height Alto de la ventana
		 */
		Game(const char * window_name, int width, int height);

	public:
		/**
		 * @brief Metodo llamado al comienzo del juego
		 * 
		 */
		void start();

		/**
		 * @brief Metodo llamado cada frame que actualiza la escena
		 * 
		 */
		void update();

		/**
		 * @brief Renderiza la escena
		 * 
		 */
		void render();

		/**
		 * @brief Resetea la escena
		 * 
		 */
		void reset();

		/**
		 * @brief Recoge los eventos, mensajeria
		 * 
		 */
		void event_handler();

	private:

		/**
		 * @brief Genera el escenario
		 * 
		 */
		void generate_world();
	};
}
