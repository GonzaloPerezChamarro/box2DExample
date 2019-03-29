#pragma once


#include "Entity.hpp"

namespace example
{
	class Game
	{
	private:
		typedef std::shared_ptr<Entity> sh_Entity;

	private:
		sf::RenderWindow window;

		Scene * scene;

	public:

		Game(const char * window_name, int width, int height);

	public:
		void start();
		void update();
		void render();
		void reset();

		void event_handler();

	private:
		void generate_world();
	};
}
