
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

namespace example
{
	template< typename OBJECT >
	class Pool
	{
		typedef OBJECT Object;
		
		class Node
		{
		public:
			
			Object object;
			Node * prev;
			Node * next;
		};

		/* Array of nodes*/
		std::vector<Node> nodes;

		/* Points to the first free node */
		Node* first_free;

		/* Points to the first node in use*/
		Node* first_used;

	public:
		/* Class iterator, for iterate between nodes */
		class Iterator
		{
			Node * current;

		public:

			Iterator(Node * start)
			{
				current = start;
			}

			Iterator(const Iterator &) = default;

			Iterator & operator ++ ()
			{
				current = current->next;
				return *this;
			}

			Iterator operator ++ (int)
			{
				Iterator copy(*this);
				current = current->next;
				return copy;
			}

			Object & operator * ()
			{
				return current->object;
			}

			bool operator == (const Iterator & other) const
			{
				return this->current == other.current;
			}

			bool operator != (const Iterator & other) const
			{
				return this->current != other.current;
			}
		};

	public:
		/* Constructor */
		Pool(size_t size) : nodes(size)
		{
			if (size > 0)
				this->first_free = &nodes[0];
			else
				first_free = nullptr;

			if (size > 1)
			{
				first_free->next = &nodes[1];
			}
			first_free->prev = nullptr;

			this->first_used = nullptr;


			Node * current = first_free->next;

			for (int i = 1; i < nodes.size() -1; ++i)
			{
				current = &nodes[i];
				current->prev = &nodes[i - 1];
				current->next = &nodes[i + 1];
				current = current->next;
			}

			current = &nodes[nodes.size() - 1];
			current->prev = &nodes[nodes.size() - 2];
			current->next = nullptr;
		}

		Object * get_free_object()
		{
			Node * free = first_free;

			if (free)
			{
				first_free = free->next;

				if (free->next)
				{
					free->next->prev = nullptr;
				}

				free->next = first_used;
				
				if (first_used)
				{
					first_used->prev = free;
				}
				
				first_used = free;
			}
			
			return reinterpret_cast<Object *>(free);

		}

		void free_object(Object * object)
		{
			Node * node = reinterpret_cast<Node *>(object);

			if (node->prev)
			{
				node->prev->next = node->next;
			}
			else
			{
				first_used = node->next;
			}

			if (node->next)
			{
				node->next->prev = node->prev;
			}

			node->prev = nullptr;
			node->next = first_free;

			if(first_free)
				first_free->prev = node;

			first_free = node;
		}

		Iterator begin()
		{
			return Iterator(first_used);
		}

		Iterator end()
		{
			return Iterator(nullptr);
		}
	};
}
