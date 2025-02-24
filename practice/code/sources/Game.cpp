
#include "Game.hpp"
#include "Entity.hpp"
#include "Listener.hpp"

namespace example
{

	Game::Game(const char * window_name, int width, int height)
		: window(sf::VideoMode(width, height), window_name,
			sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32)),
			scene( new Scene(window.getSize().x, window.getSize().y, 10.f, 10.f))
	{
		window.setFramerateLimit(60);

		scene->set_game(this);
		scene->generate_world();

		scene->get_world().SetContactListener(new Listener);
	}

	void Game::start()
	{
		update();
	}

	void Game::update()
	{
		constexpr unsigned fps = 60;
		sf::Time timeUpdate = sf::seconds(1.0f / float(fps));
		sf::Clock timer;
		auto last_time = sf::Time::Zero;
		auto time = timer.getElapsedTime();
		auto deltaTime = time - last_time;

		do 
		{
			time = timer.getElapsedTime();

			scene->update(deltaTime.asSeconds());

			window.clear(sf::Color(200,210,210));
			render();
			window.display();

			event_handler();

			deltaTime = time - last_time;
			last_time = time;

		}
		while (window.isOpen());
	}

	void Game::render()
	{
		scene->render(window);
	}

	void Game::reset()
	{
		scene->get_entity_by_name("ball")->reset();
		scene->get_entity_by_name("vehicle")->reset();
	}

	void Game::event_handler()
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
	}
}
