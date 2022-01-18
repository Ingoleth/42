#ifndef CONTAINERS_MAP_HPP
# define CONTAINERS_MAP_HPP

#include <functional> // less
#include <memory> // allocator
#include <cstdlib>
#include <limits> // numeric_limits

# include "Iterator.hpp"
# include "BinaryTree.hpp"

namespace ft
{
	template<typename T, class node_type>
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

		MapIterator(node_type *_p): p(_p) {}

		MapIterator(MapIterator const &src): p(src.p) {}

		~MapIterator() {}

		operator	MapIterator<const T, node_type>(void) const
		{
			return (MapIterator<const T, node_type>(p));
		}

		node_type *base( void ) const
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

		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			this->p = p->getNext(p);
			return (tmp);
		}

		MapIterator &operator++()
		{
			this->p = p->getNext(p);
			return (*this);
		}

		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			this->p = p->getPrevious(p);
			return (tmp);
		}

		MapIterator &operator--()
		{
			this->p = p->getPrevious(p);
			return (*this);
		}

		protected:
			node_type *p;
	};

	template<typename T, typename nodeT, typename U, typename nodeU>
	bool operator==(MapIterator<T, nodeT> const &a, MapIterator<U, nodeU> const &b)
	{
		return (a.base() == b.base());
	}

	template<typename T, typename nodeT, typename U, typename nodeU>
	bool operator!=(MapIterator<T, nodeT> const &a, MapIterator<U, nodeU> const &b)
	{
		return (a.base() != b.base());
	}

	template<class _Key, class _Tp, class _Compare = std::less<_Key>, class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{	

	public:

		typedef _Key													key_type;
		typedef _Tp														mapped_type;
		typedef ft::pair<const _Key, _Tp>								value_type;
		typedef _Compare												key_compare;
		typedef _Alloc													allocator_type;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef BTNode<value_type>	*									binary_tree_ptr;

		typedef ft::MapIterator<value_type, BTNode<value_type> >		iterator;
		typedef ft::MapIterator<const value_type, BTNode<value_type> >	const_iterator;
		typedef typename ft::ReverseIterator<iterator>					reverse_iterator;
		typedef typename ft::ReverseIterator<const_iterator>			const_reverse_iterator;
		typedef typename allocator_type::size_type						size_type;
		typedef std::ptrdiff_t											difference_type;

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

		//explicit map( const _Compare& comp, const _Alloc& alloc = Alloc() );

		map() : _mem(), _compare(), _allocator()
		{
			ghost = new BTNode<value_type>();
			tree = ghost;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const _Compare& comp = _Compare(), const _Alloc& alloc = _Alloc() ): _compare(comp), _allocator(alloc)
		{
			ghost = new BTNode<value_type>();
			tree = ghost;

			while (first != last)
			{
				insert(*first);
				first++;
			}
		};

		map(const map &src) : _mem(src._mem), _compare(src._compare), _allocator(src._allocator)
		{
			tree = src.tree->copy(src.tree);
			ghost = tree->findBiggestNode(tree);
		}

		~map()
		{
			if (tree) //Probably not needed...
				delete tree;
		}

		map& operator=( const map& other )
		{
			if (tree)
				delete tree;
			tree = other.tree->copy(other.tree);
			ghost = tree->findBiggestNode(tree);
			return (*this);
		}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/
		iterator begin()
		{
			return (iterator(tree->findSmallestNode(tree)));
		}

		const_iterator begin() const
		{
			return (const_iterator(tree->findSmallestNode(tree)));
		}

		iterator end()
		{
			return (iterator(ghost));
		}

		const_iterator end() const
		{
			return (const_iterator(ghost));
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
		return (tree != ghost);
	}

	size_type size ( void ) const
	{
		return (tree->size(tree) - 1);
	}

	size_type   max_size(void) const //handle allocator stuff...
	{
		return std::numeric_limits<difference_type>::max() / (sizeof(BTNode<value_type>));
	}

	/*
	** ------------------------------ ELEMENT ACCESS -------------------------------
	*/

	mapped_type	&operator[] (const key_type &key)
	{
		return (*((this->insert(ft::make_pair(key, mapped_type()))).first)).second;
	}


	/*
	** --------------------------------- MODIFIERS ---------------------------------
	*/

	void clear()
	{
		removeGhost();
		delete tree;
		tree = ghost;
	}

	pair<iterator,bool> insert (const value_type& val)
	{
		removeGhost();
		ft::pair<BTNode<value_type> *, bool> ret = addNode(val, &tree);
		insertGhost();
		return (ft::make_pair(iterator(ret.first), ret.second));
	}

	iterator insert (iterator position, const value_type& val)
	{
		binary_tree_ptr aux;
		removeGhost();
		binary_tree_ptr ptr = position.base();
		if (ptr != ghost && _compare((ptr->findSmallestNode(ptr)->data).first, val.first))
			aux = addNode(val, &ptr).first;
		else
			aux = addNode(val, &tree).first;
		insertGhost();
		return (iterator(aux));
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
			insert(*first);
	}

	template<class InputIterator>
	void erase (InputIterator position)
	{
		removeNode(*position, &tree);
	}

	size_type erase (const key_type& k)
	{
		return (removeNode(ft::make_pair(k, mapped_type()), &tree));
	}
	
template<class InputIterator>
	void erase (InputIterator first, InputIterator last) //How da fuck do I remove stuff without you removing all the things?
	{
		for (InputIterator aux = first++; first != last; first = aux)
			removeNode(*first, &tree);
	}

	void swap (map& x)
	{
		std::swap(tree, x.tree);
		std::swap(_mem, x._mem);
		std::swap(_compare, x._compare);
		std::swap(_allocator, x._allocator);
		std::swap(ghost, x.ghost);
	}

	void debugMap() //TODO: Remove;
	{
		tree->displayTree(tree);
	}

	void balanceMap()
	{
		removeGhost();
		tree = balanceTreeNode(tree);
		insertGhost();
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
			iterator it = findInNode(k, tree);

			if (it.base())
				return it;
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			iterator it = findInNode(k, tree);

			if (it.base())
				return it;
			return end();
		}

		size_type count (const key_type& k) const
		{
			return (static_cast <size_type> (static_cast <bool> (findInNode(k, tree))));
		}

		//Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		iterator lower_bound (const key_type& k)
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost &&_compare(aux->data.first, k))
				aux = aux->getNext(aux);
			return (aux);
		}

		const_iterator lower_bound (const key_type& k) const
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost &&_compare(aux->data.first, k))
				aux = aux->getNext(aux);
			return (aux);
		}

		iterator upper_bound (const key_type& k)
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost &&_compare(k, aux->data.first))
				aux = aux->getNext(aux);
			return (aux);
		}

		const_iterator upper_bound (const key_type& k) const
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost &&_compare(k, aux->data.first))
				aux = aux->getNext(aux);
			return (aux);
		}

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost && _compare(aux->data.first, k))
				aux = aux->getNext(aux);
			if (_are_equivalent(aux->data.first, k))
				return ft::make_pair(aux, aux->getNext(aux));
			else
				return ft::make_pair(aux, aux);
		}
		
		ft::pair<iterator,iterator>	equal_range (const key_type& k)
		{
			binary_tree_ptr aux;

			aux = tree->findSmallestNode(tree);
			while (aux != ghost && _compare(aux->data.first, k))
				aux = aux->getNext(aux);
			if (_are_equivalent(aux->data.first, k))
				return ft::make_pair(aux, aux->getNext(aux));
			else
				return ft::make_pair(aux, aux);
		}

	/*
	** --------------------------------- ALLOCATOR ---------------------------------
	*/

		allocator_type get_allocator() const
		{
			return (_mem);
		}

	protected:
		binary_tree_ptr			tree;
		allocator_type		_mem;
		key_compare			_compare;
		allocator_type		_allocator;
		binary_tree_ptr			ghost;
	
	private:

		bool	_are_equivalent(key_type key1, key_type key2) const
		{
			return (!_compare(key1, key2) && !_compare(key2, key1));
		}

		binary_tree_ptr findInNode(const key_type &to_find, binary_tree_ptr node) const
		{
			if (!node)
				return (NULL);
			if (to_find == node->data.first)
				return (node);
			if (_compare(to_find, node->data.first))
				return (findInNode(to_find, node->left));
			return (findInNode(to_find, node->right));
		}

		binary_tree_ptr findInNode(const key_type &to_find, const binary_tree_ptr &node, binary_tree_ptr &lastNode) const
		{
			if (!node)
				return (NULL);
			lastNode = node;
			if (to_find == node->data.first)
				return (node);
			if(_compare(to_find, (node->data).first))

				return (findInNode(to_find, node->left, lastNode));
			return (findInNode(to_find, node->right, lastNode));
		}

		pair<binary_tree_ptr, bool>addNode(const value_type& _data, binary_tree_ptr *root)
		{
			binary_tree_ptr aux;

			if (!*root)
			{
				*root = new BTNode<value_type>(_data);
				return ft::make_pair(*root, true);
			}
			if (findInNode(_data.first, *root, aux))
				return ft::make_pair(aux, false);
			if (_data.first < aux->data.first)
			{
					aux->left = new BTNode<value_type>(_data);
					aux->left->top = aux;
					aux = aux->left;
			}
			else
			{
					aux->right = new BTNode<value_type>(_data);
					aux->right->top = aux;
					aux = aux->right;
			}
			return(ft::make_pair(aux, true));
		}

		void insert_node(binary_tree_ptr node, binary_tree_ptr parent)
		{
			if (!node || !parent)
				return ;
			findInNode(node->data.first, parent, parent);
			if (_compare((parent->data).first, (node->data).first))
				parent->right = node;
			else
				parent->left = node;
			node->top = parent;
		}

		binary_tree_ptr balanceTreeNode(binary_tree_ptr Node)
		{
			if (!Node)
				return NULL;
			int imbalance;
			binary_tree_ptr aux;

			while (true)
			{
				imbalance = Node->height(Node->left) - Node->height(Node->right);
				aux = Node;
				if (imbalance <= -2)
				{
					Node = Node->right;
					aux->right = NULL;
				}
				else if (imbalance >= 2)
				{
					Node = Node->left;
					aux->left = NULL;
				}
				else
					break ;
				Node->top = aux->top;
				insert_node(aux, Node);
			}
			Node->left = balanceTreeNode(Node->left);
			Node->right = balanceTreeNode(Node->right);
			return (Node);
		}

		bool removeNode(const value_type& _data, binary_tree_ptr *root)
		{
			binary_tree_ptr aux = NULL;

			removeGhost();
			if (!*root || !(aux = findInNode(_data.first, *root)))
			{
				insertGhost();
				return false;
			}
			if (*root == aux)
			{
				*root = (*root)->right;
				(*root)->top = NULL;
				insert_node(aux->left, *root);
			}
			else
			{
				if (_compare(aux->top->data.first, aux->data.first))
					aux->top->right = NULL;
				else
					aux->top->left = NULL;
				insert_node(aux->left, aux->top);
				insert_node(aux->right, aux->top);
			}
			aux->right = NULL;
			aux->left = NULL;
			delete aux;
			insertGhost();
			return true;
		}

		void removeGhost()
		{
			if (tree != ghost)
				ghost->top->right = NULL;
			else
				tree = NULL;
		}

		void insertGhost()
		{
			binary_tree_ptr aux = tree->findBiggestNode(tree);
			if (aux)
				aux->right = ghost;
			else
				tree = ghost;
			ghost->top = aux;
		}
	};

		template <class Key, class T, class Compare, class Alloc>
		bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs == rhs);
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator< ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(rhs < lhs);
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator> ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return (rhs < lhs);
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs < rhs);
		}


/*
** -------------------------------- LOGICAL OPERATORS ------------------------------
*/

}

#endif