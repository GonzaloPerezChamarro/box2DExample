
/**
 * @file Pool.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Basic pool of objects
 * @version 1.0
 * @date 2019-04-16
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <list>

namespace example
{
	template< typename OBJECT >
	class Pool
	{
		typedef OBJECT Object;

	public:
		/* Constructor */
		Pool(size_t size = 0)
		{
			for (size_t i = 0; i < size; ++i)
			{
				objects.emplace_back(Object());
				free_objs.push_back(&objects.back());
			}
		}

		Object* get_free_object()
		{
			if (!free_objs.empty())
			{
				used_objs.push_back(free_objs.back());
				free_objs.pop_back();
			}
			else
			{
				objects.emplace_back(Object());
				used_objs.push_back(&objects.back());
			}

			return used_objs.back();
		}

		void free_object(Object * object)
		{
			used_objs.remove(object);
			free_objs.push_back(object);
		}

	private:
		/* Pool of objects */
		std::list<Object> objects;

		/* List of pointers to the free objects */
		std::list<Object*> free_objs;

		/* List of pointers to the used objects */
		std::list<Object*> used_objs;
	};
}
