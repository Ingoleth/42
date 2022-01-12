#ifndef CONTAINERS_MAP_HPP
# define CONTAINERS_MAP_HPP

# include <functional>
# include <memory>

# include "Iterator.hpp"
# include "BinaryTree.hpp"

namespace ft
{
	template<typename T>
	class MapIterator : public IteratorTrait<T>
	{
		public:
			typedef T																value_type;
			typedef value_type														*pointer;
			typedef value_type														const * const_pointer;
			typedef value_type														&reference;
			typedef value_type const												&const_reference;
			typedef std::ptrdiff_t													difference_type;
			typedef std::bidirectional_iterator_tag									iterator_category;

		MapIterator(): p(0) {}

		MapIterator(BTNode<value_type> *_p): p(_p) {}

		MapIterator(MapIterator const &src): p(src.p) {}

		~MapIterator() {}

		BTNode<value_type> *base( void )
		{
			return (p);
		}

		MapIterator &operator=(MapIterator const &src)
		{
			this->p = src.p;
			return (*this);
		}

		reference operator*()
		{
			return (p->data);
		}
		const_reference operator*() const
		{
			return (p->data);
		}

		pointer operator->()
		{
			return (&p->data);
		}
		const_pointer operator->() const
		{
			return (&p->data);
		}

		/*
			MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			++this->p;
			return (tmp);
		}

		MapIterator &operator++()
		{
			++this->p;
			return (*this);
		}

		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			--this->p;
			return (tmp);
		}

		MapIterator &operator--()
		{
			--this->p;
			return (*this);
		}
		*/

		protected:
			BTNode<value_type> *p;
	};

	template<class _Key, class _Tp, class _Compare = std::less<_Key>, class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{	

	public:

		typedef _Key											key_type;
		typedef _Tp												mapped_type;
		typedef ft::pair<const _Key, _Tp>						value_type;
		typedef _Compare										key_compare;
		typedef _Alloc											allocator_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;

		typedef ft::MapIterator<value_type>						iterator;
		typedef ft::MapIterator<const value_type>				const_iterator;
		typedef typename ft::ReverseIterator<iterator>			reverse_iterator;
		typedef typename ft::ReverseIterator<const_iterator>	const_reverse_iterator;
		typedef typename allocator_type::size_type				size_type;
		//typedef typename _Rep_type::difference_type			difference_type;

	/*									 
	** --------------------------------- CONSTRUCTOR ---------------------------------
	*/

		map() : tree(NULL), _mem() {}

		~map()
		{
			if (tree)
				delete tree;
		}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/
		iterator begin()
		{
			return (findSmallestNode(tree));
		}

		const_iterator begin() const
		{
			return (findSmallestNode(tree));
		}

		iterator end()
		{
			return (0);
		}

		const_iterator end() const //TODO: Figure out how to handle end...
		{
			return (0);
		}

		reverse_iterator rbegin()
		{
			return (end());
		}

		const_reverse_iterator rbegin() const
		{
			return (end());
		}

		reverse_iterator rend()
		{
			return (begin());
		}

		const_reverse_iterator rend() const
		{
			return (begin());
		}

	/*									 
	** -------------------------------- CAPACITY ---------------------------------
	*/

	bool empty() const
	{
		return (!static_cast <bool> (tree));
	}

	size_type size ( void ) const
	{
		return (tree->size(tree));
	}

	size_type   max_size(void) const //handle allocator stuff...
	{
		return _mem.max_size();
	}

	/*
	** ------------------------------ ELEMENT ACCESS -------------------------------
	*/

	/*
	** --------------------------------- MODIFIERS ---------------------------------
	*/

	pair<iterator,bool> insert (const value_type& val)
	{
		ft::pair<BTNode<value_type> *, bool> ret = addNode(val, &tree);

		return (ft::make_pair(iterator(ret.first), ret.second));
	}

	iterator insert (iterator position, const value_type& val)
	{
		BTNode <value_type>*ptr = position.base();
		if (ptr->findSmallest()->data < val)
			addNode(val, &ptr);
		else
			addNode(val, &tree);
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
			addNode(*first, &tree);
	}

	void erase (iterator position)
	{
		tree->remove(*position, tree);
	}

	/*size_type erase (const key_type& k)
	{
	}*/
	
	void erase (iterator first, iterator last) //How da fuck do I remove stuff without you removing all the things?
	{
		for (iterator aux = first++; first != last; first = aux)
			erase(first);
	}

	void swap (ft::map< _Key, _Tp, _Compare, _Alloc>& x)
	{
		swap(this->tree, x.tree);
		swap(this->_mem, x._mem);
	}

	void debugMap()
	{
		tree->displayTree(tree);
	}

	/*
	** --------------------------------- OBSERVERS ---------------------------------
	*/

	/*
	** --------------------------------- OPERATIONS --------------------------------
	*/

		iterator find (const key_type& k)
		{
			iterator it = tree->findInNode(k, tree);

			if (it)
				return it;
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			iterator it = tree->findInNode(k, tree);

			if (it)
				return it;
			return end();
		}

		size_type count (const key_type& k) const
		{
			return (static_cast <size_type> (static_cast <bool> (findInNode(k, tree))));
		}

		iterator lower_bound (const key_type& k); //Think it through
		const_iterator lower_bound (const key_type& k) const; //think it through
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;

		//pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
		
		//pair<iterator,iterator>	equal_range (const key_type& k);

	/*
	** --------------------------------- ALLOCATOR ---------------------------------
	*/

		allocator_type get_allocator() const
		{
			return (_mem);
		}

	private:
		BTNode<value_type> *tree;
		allocator_type _mem;
	};

/*
** -------------------------------- LOGICAL OPERATORS ------------------------------
*/

}

#endif