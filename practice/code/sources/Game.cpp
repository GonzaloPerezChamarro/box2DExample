
#include "Game.hpp"
#include "Entity.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Listener.hpp"
#include "Platform.hpp"
#include "Vehicle.hpp"
#include "Sensor.hpp"
#include "Hook.hpp"
#include "FireParticle.hpp"
#include "ParticleSystem.hpp"

namespace example
{

	Game::Game(const char * window_name, int width, int height)
		: window(sf::VideoMode(width, height), window_name,
			sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32)),
			scene( new Scene(window.getSize().x, window.getSize().y, 10.f, 10.f))
	{
		window.setFramerateLimit(60);


		generate_world();

		Listener * listener = new Listener;
		scene->get_world().SetContactListener(listener);
		scene->set_game(this);

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

		} while (window.isOpen());
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

	void Game::generate_world()
	{
		scene->add_entity("ball", sh_Entity(new Circle(100.f, 300.f, 17.f, scene)));
		scene->get_entity_by_name("ball")->set_tag("ball");

		//Suelo principal
		scene->add_entity("floor01", sh_Entity(new Rectangle(scene, 55.f, 50.f, 110.f, 100.f)));
		scene->add_entity("floor02", sh_Entity(new Rectangle(scene, 210.f, -7.f, 121.f, 112.f, -30.f)));
		scene->add_entity("floor03", sh_Entity(new Rectangle(scene, 200.f, 20.f, 800.f, 40.f)));

		
		//suelo en altura
		scene->add_entity("floor04", sh_Entity(new Rectangle(scene, 500.f, 410.f, 100.f, 20.f)));
		scene->add_entity("floor05", sh_Entity(new Rectangle(scene, 672.f, 465.f, 100.f, 20.f, 35.f)));
		scene->add_entity("floor06", sh_Entity(new Rectangle(scene, 868.f, 518.f, 130.f, 20.f)));

		//V final
		scene->add_entity("floor07", sh_Entity(new Rectangle(scene, 60.f, 540.f, 70.f, 15.f, -45.f)));
		scene->add_entity("floor08", sh_Entity(new Rectangle(scene, 140.f, 540.f, 70.f, 15.f, 45.f)));
		
		//Plataformas dinamicas
		scene->add_entity("platform01", sh_Entity(new Platform(scene, 1132.f, 40.f, 130.f, 20.f, b2Vec2(1132.f, 518.f), 10.f)));
		scene->add_entity("platform02", sh_Entity(new Platform(scene, 298, 410.f, 95.f, 20.f, b2Vec2(298, 565), 10.f)));
		
		//Sensores
		scene->add_entity("sensor1", sh_Entity(new Sensor(scene, 1142.f, 90.f, 110.f, 30.f, "platform01")));
		scene->add_entity("sensor2", sh_Entity(new Sensor(scene, 308, 465.f, 75.f, 30.f, "platform02")));

		//Vehiculo
		scene->add_entity("vehicle", sh_Entity(new Vehicle(scene, 95.f, 230.f)));

		//PAREDES
		scene->add_entity("left_wall", sh_Entity(new Rectangle(scene, -5.f,720.f *0.5f, 10.f, 720.f)));
		scene->add_entity("right_wall", sh_Entity(new Rectangle(scene,1280.f + 5.f, 720.f *0.5f, 10.f, 720.f)));
		
		//HOOK
		scene->add_entity("hook", sh_Entity(new Hook(scene, 600.f, 390.f)));

		//FIRE
		scene->add_entity("fire", sh_Entity(new Particle_System<Fire_Particle>(scene, b2Vec2(63.f, 12.f), 15, 0.4f)));
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