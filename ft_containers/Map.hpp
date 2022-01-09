#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <functional>
# include <memory>

# include "utils.hpp"
# include "Iterator.hpp"
# include "BinaryTree.hpp"

namespace ft
{
	template<typename T>
	class MapIterator : public IteratorTrait<T>
	{
		public:
			typedef T																value_type;
			typedef BTNode<value_type>												*pointer;
			typedef value_type														const * const_pointer;
			typedef value_type														&reference;
			typedef value_type const												&const_reference;
			typedef std::ptrdiff_t													difference_type;
			typedef std::bidirectional_iterator_tag									iterator_category;

		protected:
			pointer p;

		VectorIterator(): p(0) {}

		VectorIterator(const pointer _p): p(_p) {}

		VectorIterator(VectorIterator const &src): p(src.p) {}

		virtual ~VectorIterator() {}

		BTNode *base( void )
		{
			return (p);
		}

		VectorIterator &operator=(VectorIterator const &src)
		{
			this->p = src.p;
			return (*this);
		}

		reference operator*()
		{
			return (*this->p.data);
		}
		const_reference operator*() const
		{
			return (*this->p.data);
		}

		pointer operator->()
		{
			return (this->p);
		}
		const_pointer operator->() const
		{
			return (this->p);
		}

		/*
			VectorIterator operator++(int)
		{
			VectorIterator tmp(*this);
			++this->p;
			return (tmp);
		}

		VectorIterator &operator++()
		{
			++this->p;
			return (*this);
		}

		VectorIterator operator--(int)
		{
			VectorIterator tmp(*this);
			--this->p;
			return (tmp);
		}

		VectorIterator &operator--()
		{
			--this->p;
			return (*this);
		}
		*/
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

		map() : ptr()
		{

		}

		map(/* args */)
		{

		}
	
		~map() //TODO: Check node memory management...
		{

		}

		~map()
		{

		}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/
		iterator begin()
		{
			return (tree->findSmallest(tree));
		}

		const_iterator begin() const
		{
			return (tree->findSmallest(tree));
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
		if (!tree)
			return (make_pair((tree = new BTNode(val)), true));
		else
			return(add(val, root));
	}

	iterator insert (iterator position, const value_type& val)
	{
		BTNode *ptr = position.base();
		if (ptr->data < val)
			add(val, ptr);
		else
			add(val, root);
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
			insert(*first);
	}

	void erase (iterator position)
	{
		tree->remove(*position, tree); //TODO:pair stuff, ya know...
	}

	/*size_type erase (const key_type& k)
	{
	}*/
	
	void erase (iterator first, iterator last); //How da fuck do I remove stuff without you removing all the things?
	{
		for (iterator aux = first++; first != last; first = aux)
			erase(first);
	}

	void swap (ft::map< _Key, _Tp, _Compare, _Alloc>& x)
	{
		swap(this->tree, x.tree);
		swap(this->_mem, x._mem);
	}

	/*
	** --------------------------------- OBSERVERS ---------------------------------
	*/

	/*
	** --------------------------------- OPERATIONS --------------------------------
	*/

		iterator find (const key_type& k)
		{
			iterator it = tree->find(k, tree);

			if (it)
				return it;
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			iterator it = tree->find(k, tree);

			if (it)
				return it;
			return end();
		}

		size_type count (const key_type& k) const
		{
			return (static_cast <size_type> (static_cast <bool> (find(k, tree))));
		}

		iterator lower_bound (const key_type& k); //Think it through
		const_iterator lower_bound (const key_type& k) const; //think it through
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;

		pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
		pair<iterator,iterator>	equal_range (const key_type& k);

	/*
	** --------------------------------- ALLOCATOR ---------------------------------
	*/

		allocator_type get_allocator() const
		{
			return (_mem);
		}

	private:
		BTNode<ft::pair<Key, T> > *tree;
		allocator_type _mem;
	};

/*
** -------------------------------- LOGICAL OPERATORS ------------------------------
*/

}

#endif