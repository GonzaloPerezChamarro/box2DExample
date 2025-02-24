/**
 * @file Game.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a game
 * @version 1.0
 * @date 2019-04-16
 * 
 * @copyright Copyright (c) 2025
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

	public:
		/**
		 * @brief Constructor
		 * @param window_name Name of the window
		 * @param width Width of the window
		 * @param height Height of the window
		 */
		Game(const char * window_name, int width, int height);

	public:
		/* Called at the begining of the game */
		void start();

		/* Called every tick */
		void update();

		/* Renders the scene */
		void render();

		/* Reset the scene */
		void reset();

		/* Handle game events */
		void event_handler();

	private:
		/* Game window */
		sf::RenderWindow window;

		/* Pointer to game scene */
		Scene* scene;
	};
}
