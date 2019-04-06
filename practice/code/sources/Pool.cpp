
/*
#include "Pool.hpp"

#include "Entity.hpp"

namespace example
{
	Pool::Pool(Entity * entity, size_t initial_amount)
	{
		main_obj = entity;
		main_obj->set_enabled(false);
		start_amount = initial_amount;
		
		while (initial_amount > 0)
		{
			add_to_pool();
			--initial_amount;
		}
	}

	void Pool::add_to_pool()
	{
		sh_Object new_obj(main_obj);
		pooled_entities.push_back(new_obj);

	}

	void Pool::reset_pool()
	{
		while (active_entities.size() > 0)
		{
			sh_Object obj = active_entities.back();
			active_entities.pop_back();
			obj->set_enabled(false);

			pooled_entities.push_back(obj);
		}
	}

	void Pool::return_to_pool(Entity * obj)
	{
		for (auto o : active_entities)
		{
			if ((o).get() == obj)
			{
				o->set_enabled(false);
				pooled_entities.push_back(o);
				active_entities.remove(o);
			}
		}
	}

	Entity * Pool::get_object()
	{
		if (pooled_entities.size() == 0)
			add_to_pool();


		sh_Object obj = pooled_entities.back();
		active_entities.pop_back();
		obj->set_enabled(false);

		active_entities.push_back(obj);
		return (obj).get();
	}





}*/