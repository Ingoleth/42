#ifndef CONTAINERS_MAP_HPP
# define CONTAINERS_MAP_HPP

#include <functional> // less
#include <memory> // allocator
#include <cstdlib>
#include <limits> // numeric_limits

# include "Iterator.hpp"
# include "BinaryTree.hpp"
# include <map>

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
		typedef Node< value_type >										nodeType;
		typedef nodeType												*nodePtr;

		typedef ft::MapIterator<value_type, nodeType >					iterator;
		typedef ft::MapIterator<const value_type, nodeType >			const_iterator;
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

		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : tree(comp, alloc) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const _Compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ): tree(comp, alloc)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		};

		map(const map &src) : tree(src.tree) {}

		~map() {}

		map& operator=( const map& src )
		{
			tree = src.tree;
			return (*this);
		}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/
		iterator begin()
		{
			return (iterator(tree.minimum(tree.getRoot())));
		}

		const_iterator begin() const
		{
			return (const_iterator(tree.minimum(tree.getRoot())));
		}

		iterator end()
		{
			return (iterator(tree.getTNull()));
		}

		const_iterator end() const
		{
			return (const_iterator(tree.getTNull()));
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
		return (tree.empty());
	}

	size_type size ( void ) const
	{
		return (tree.size());
	}

	void debug()
	{
		tree.prettyPrint();
	}

	size_type   max_size(void) const
	{
		return std::numeric_limits<difference_type>::max() / (sizeof(nodeType));
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
		tree.clear();
	}

	pair<iterator,bool> insert(const value_type& val)
	{
		ft::pair<nodePtr, bool> ret = tree.insert(val);
		return (ft::make_pair(iterator(ret.first), ret.second));
	}

	iterator insert(iterator position, const value_type& val) //TODO:hmmmmm
	{
			static_cast<void>(position);
			ft::pair<nodePtr, bool> ret = tree.insert(val);
			return (iterator(ret.first));
	}

	template <class InputIterator>
	void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
	{
		for (; first != last; first++)
			insert(*first);
	}

	size_type erase (const key_type& k)
	{
		return (tree.deleteNode(k));
	}

	void erase (iterator position)
	{
		tree.deleteNode(position->first);
	}
	
template<class InputIterator>
	void erase (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
	{
		iterator it = first;
		while (first != last)
		{
			++first;
			erase(it);
			it = first;
		}
	}

	void swap (map& x) //Todo?
	{
		tree.swap(x.tree);
	}

	/*
	** --------------------------------- OBSERVERS ---------------------------------
	*/


		key_compare key_comp() const { return tree.getCompare(); }

		value_compare value_comp() const { return value_compare(key_compare()); }

	/*
	** --------------------------------- OPERATIONS --------------------------------
	*/

		iterator find (const key_type& k)
		{
			iterator it = tree.searchTree(k);

			if (it.base())
				return it;
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			iterator it = tree.searchTree(k);

			if (it.base())
				return it;
			return end();
		}

		size_type count (const key_type& k) const
		{
			return (static_cast <size_type> (static_cast <bool> (tree.searchTree(k))));
		}

		//Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		iterator lower_bound (const key_type& k)
		{
			nodePtr aux;

			aux = tree.minimum(tree.getRoot());
			while (aux != tree.getTNull() &&tree.getCompare()(aux->data.first, k))
				aux = tree.getNext(aux);
			return (aux);
		}

		const_iterator lower_bound (const key_type& k) const
		{
			nodePtr aux;

			aux = tree.minimum(tree.getRoot());
			while (aux != tree.getTNull() && tree.getCompare()(aux->data.first, k))
				aux = tree.getNext(aux);
			return (aux);
		}

		iterator upper_bound (const key_type& k)
		{
			nodePtr aux;
			
			aux = tree.minimum(tree.getRoot());
			while (aux != tree.getTNull() && !tree.getCompare()(k, aux->data.first))
				aux = tree.getNext(aux);
			return (aux);
		}

		const_iterator upper_bound (const key_type& k) const
		{
			nodePtr aux = tree.minimum(tree.getRoot());

			while (aux != tree.getTNull() && !tree.getCompare()(k, aux->data.first))
				aux = tree.getNext(aux);
			return (aux);
		}

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
		{
			nodePtr aux;

			aux = tree.minimum(tree.getRoot());
			while (aux != tree.getTNull() && tree.getCompare()(aux->data.first, k))
				aux = tree.getNext(aux);
			if (_are_equivalent(aux->data.first, k))
				return ft::make_pair(aux, aux->getNext(aux));
			else
				return ft::make_pair(aux, aux);
		}
		
		ft::pair<iterator,iterator>	equal_range (const key_type& k)
		{
			nodePtr aux;

			aux = tree.minimum(tree.getRoot());
			while (aux != tree.getTNull() && tree.getCompare()(aux->data.first, k))
				aux = tree.getNext(aux);
			if (_are_equivalent(aux->data.first, k))
				return ft::make_pair(aux, aux->getNext(aux));
			else
				return ft::make_pair(aux, aux);
		}

	/*
	** --------------------------------- ALLOCATOR ---------------------------------
	*/

		allocator_type get_allocator() const //TODO: CHECK
		{
			return (_Alloc());
		}

	protected:

		RBTree<_Key, _Tp, _Compare, _Alloc> tree;
	
	private:

		bool	_are_equivalent(key_type key1, key_type key2) const
		{
			return (!tree.getCompare()(key1, key2) && !tree.getCompare()(key2, key1));
		}
	};

		template <class Key, class T, class Compare1, class Alloc1, class Compare2, class Alloc2>
		bool operator== ( const ft::map<Key,T,Compare1,Alloc1>& lhs, const std::map<Key,T,Compare2,Alloc2>& rhs )
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class Key, class T, class Compare1, class Alloc1, class Compare2, class Alloc2>
		bool operator== ( const std::map<Key,T,Compare1,Alloc1>& lhs, const ft::map<Key,T,Compare2,Alloc2>& rhs )
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class Key, class T, class Compare, class Alloc>
		bool operator== ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
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