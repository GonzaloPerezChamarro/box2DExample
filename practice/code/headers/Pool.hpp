#pragma once

#include <list>
#include <vector>

#include "Entity.hpp"


namespace example
{
	using namespace std;

	class Entity;
	class Pool
	{
	public:
		typedef std::shared_ptr<Entity> sh_Object;

	private:

		std::list<sh_Object> pooled_entities;
		std::list<sh_Object> active_entities;

		Entity * main_obj;
		size_t start_amount;

	public:

		Pool(Entity * entity, size_t initial_amount = 32);


	public:

		void add_to_pool();

		void reset_pool();

		void return_to_pool(Entity * obj);

		Entity * get_object();

		std::list<sh_Object> get_active_entities() { return active_entities; }
	};

}
