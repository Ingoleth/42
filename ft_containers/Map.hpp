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
		typedef BTNode<value_type>	*							binary_tree;

		typedef ft::MapIterator<value_type>						iterator;
		typedef ft::MapIterator<const value_type>				const_iterator;
		typedef typename ft::ReverseIterator<iterator>			reverse_iterator;
		typedef typename ft::ReverseIterator<const_iterator>	const_reverse_iterator;
		typedef typename allocator_type::size_type				size_type;
		//typedef typename _Rep_type::difference_type			difference_type;

		class value_compare
		{
			friend class map;
		protected:
			key_compare comp;
			value_compare (key_compare c): comp(c) {}
		
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return (comp(x.first, y.first));
			}
		};


	/*									 
	** --------------------------------- CONSTRUCTOR ---------------------------------
	*/

		map() : tree(NULL), _mem(), _compare(), _allocator() {}

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
			return (tree->findSmallestNode(tree));
		}

		const_iterator begin() const
		{
			return (tree->findSmallestNode(tree));
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

	void swap (ft::map< _Key, _Tp, key_compare, _Alloc>& x)
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


		key_compare key_comp() const { return _compare; }

		value_compare value_comp() const { return value_compare(key_compare()); }

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

	protected:
		binary_tree			tree;
		allocator_type		_mem;
		key_compare			_compare;
		allocator_type		_allocator;
	
	private:

		binary_tree findInNode(value_type to_find, binary_tree node)
		{
			if (!node)
				return (NULL);
			if (to_find == node->data)
				return (node);
			if (_compare(to_find.first, (node->data).first))
				return (findInNode(to_find, node->left));
			return (findInNode(to_find, node->right));
		}

		binary_tree findInNode(value_type to_find, binary_tree node, binary_tree *lastNode)
		{
			if (!node)
				return (NULL);
			if (to_find == node->data)
				return (node);
			*lastNode = node;
			if(_compare(to_find.first, (node->data).first))

				return (findInNode(to_find, node->left, lastNode));
			return (findInNode(to_find, node->right, lastNode));
		}

		pair<binary_tree, bool>addNode(const value_type& _data, binary_tree *root)
		{
			binary_tree aux;

			if (!*root)
			{
				*root = new BTNode<value_type>(_data);
				return ft::make_pair(*root, true);
			}
			if (findInNode(_data, *root, &aux))
				return ft::make_pair(aux, false);
			return(ft::make_pair(new BTNode<value_type>(_data, aux), true));
		}

		void insert_node(binary_tree node, binary_tree parent)
		{
			if (!node || !parent)
				return ;
			findInNode(node->data, parent, &parent);
			if (_compare((parent->data).first, (node->data).first))
				parent->right = node;
			else
				parent->left = node;
			node->top = parent;
		}

		void balanceTree(binary_tree *Node)
		{
			if (!*Node)
				return;

			int imbalance = heigth((*Node)->left) - heigth((*Node)->right);
			binary_tree aux = NULL;

			while (imbalance <= -2)
			{
				aux = *Node;
				*Node = (*Node)->right;
				(*Node)->top = aux->top;
				aux->right = NULL;
				insert_node(aux, *Node);
				imbalance += 2;
			}
			while (imbalance >= 2)
			{
				aux = *Node;
				*Node = (*Node)->left;
				(*Node)->top = aux->top;
				aux->left = NULL;
				insert_node(aux, *Node);
				imbalance -= 2;
			}
			balanceTree(&(*Node)->left);
			balanceTree(&(*Node)->right);
		}

		void removeNode(const value_type& _data, binary_tree *root)
		{
			binary_tree aux = NULL;

			if (!*root || !(aux = findInNode(_data, *root)))
				return ;
			if (*root == aux)
			{
				*root = (*root)->right;
				(*root)->top = NULL;
				insert_node(aux->left, *root);
			}
			else
			{
				if (aux->top->data < aux->data)
					aux->top->right = NULL;
				else
					aux->top->left = NULL;
				insert_node(aux->left, aux->top);
				insert_node(aux->right, aux->top);
			}
			delete aux;
		}
	};

/*
** -------------------------------- LOGICAL OPERATORS ------------------------------
*/

}

#endif