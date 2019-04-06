

template< typename OBJECT >
class Pool
{

	typedef OBJECT Object;

	class Node
	{
		Object object;
		Node * next;
		Node * prev;
	};

	std::vector< Node > nodes;

	Node * first_free;
	Node * first_used;

public:

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

		Iterator operator ++ ()
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

	Pool(size_t size) : nodes(size)
	{
	}

	Object * get_free_object()
	{
		if (first_free == nullptr) return nullptr;

		Node * node = first_free;
		if (first_free->next != nullptr)
		{

			first_free->prev->next = first_free->next;
		}

		first_free->next->prev = first_free->prev;

		node->next = first_used;
		node->prev = nullptr;

		first_used->prev = node;
		first_used = node;

		return reinterpret_cast<Object *>(node);
	}

	void free_object(Object * object)
	{
		Node * node = reinterpret_cast<Node *>(object);

		if (node->next != nullptr)
		{
			node->prev->next = node->next;
		}

		node->next->prev = node->prev;

		node->prev = nullptr;
		node->next = first_free;

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