#pragma once

#include <string>
#include <map>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>


namespace example
{
	using namespace std;

	class Entity;
	class Scene
	{
	private:

		typedef std::shared_ptr<Entity> sh_Entity;

	private:
		map<string, sh_Entity> entities_map;

		int width;
		int height;

		float scale;
		float gravity;

		b2World world;

	public:
		Scene(int width, int height, float scale, float gravity);
		virtual ~Scene();

	public:
		void update(float deltaTime);

		void render(sf::RenderWindow & renderer);

	public:

		b2World & get_world() {return world;}

		int get_width() {return width;}

		int get_height() {return height;}

		float get_scale() const {return scale;}

		float get_gravity() const {return gravity;}

		float scale_pixels_to_sfml(){return 1.f / scale;}


		void add_entity(const std::string name, const sh_Entity & entity);

		Entity * get_entity_by_name(const std::string & name);

		void set_particle_system(Scene * scene, sf::Vector2i position, sf::Vector2f direction, size_t num_Particles);


	};
}
