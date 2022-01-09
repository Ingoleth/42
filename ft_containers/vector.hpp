#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "utils.hpp"
# include "Iterator.hpp"
# include <limits>

namespace ft
{

	template<typename T>
	class VectorIterator : public IteratorTrait<T>
	{

	public:
		typedef T																value_type;
		typedef value_type														*pointer;
		typedef value_type														const * const_pointer;
		typedef value_type														&reference;
		typedef value_type const												&const_reference;
		typedef std::ptrdiff_t													difference_type;
		typedef std::random_access_iterator_tag									iterator_category;
	
	protected:
		pointer p;
	public:

		VectorIterator(): p(0) {}


		VectorIterator(const pointer _p): p(_p) {}

		VectorIterator(VectorIterator const &src): p(src.p) {}

		virtual ~VectorIterator() {}

		VectorIterator &operator=(VectorIterator const &src)
		{
			this->p = src.p;
			return (*this);
		}

		reference operator*()
		{
			return (*this->p);
		}
		const_reference operator*() const
		{
			return (*this->p);
		}

		pointer operator->()
		{
			return (this->p);
		}
		const_pointer operator->() const
		{
			return (this->p);
		}

		reference operator[](int val)
		{
			return (*(this->p + val));
		}

		const_reference operator[](int val) const
		{
			return (*(this->p + val));
		}

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

		VectorIterator &operator+=(difference_type value)
		{
			this->p += value;
			return (*this);
		}

		VectorIterator operator+(difference_type value) const
		{
			VectorIterator tmp(*this);
			return (tmp += value);
		}
	
		VectorIterator &operator-=(difference_type value)
		{
			this->p -= value;
			return (*this);
		}

		VectorIterator operator-(difference_type value) const //Change
		{
			VectorIterator tmp(*this);
			return (tmp -= value);
		}

		T *base() const
		{
			return (this->p);
		}

		operator VectorIterator<const T>()
		{
			return(static_cast<const T *> (p));
		}

		operator void*()
		{
			return(static_cast<void *> (p));
		}

	};

	template<typename T, typename U>
	bool operator==(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() == b.base());
	}

	template<typename T>
	bool operator==(VectorIterator<T> const &a, T *const &b)
	{
		return (a.base() == b);
	}

	template<typename T, typename U>
	bool operator!=(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() != b.base());
	}

	template<typename T, typename U>
	bool operator<(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() < b.base());
	}

	template<typename T, typename U>
	bool operator<=(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() <= b.base());
	}
	template<typename T, typename U>
	bool operator>(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() > b.base());
	}

	template<typename T, typename U>
	bool operator>=(VectorIterator<T> const &a, VectorIterator<U> const &b)
	{
		return (a.base() >= b.base());
	}

	template <typename T>
	VectorIterator<T>	operator+(int lhs, VectorIterator<T> rhs)
	{
		return (VectorIterator<T>(rhs.base() + lhs));
	}

	template<class T, class U>
	typename ft::VectorIterator<T>::difference_type
	operator-(const VectorIterator<T>& value1, const VectorIterator<U>& value2)
	{
		return value1.base() - value2.base();
	}

	template<typename T>
	std::ostream &			operator<<( std::ostream & o, VectorIterator<T> const & i )
	{
		o << i.p;
		return o;
	}

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::VectorIterator<value_type>								iterator;
			typedef ft::VectorIterator<const value_type>						const_iterator;
			typedef ft::ReverseIterator<iterator>								reverse_iterator;
			typedef ft::ReverseIterator<const_iterator>							const_reverse_iterator;
			typedef typename allocator_type::size_type							size_type;

	/*									 
	** --------------------------------- CONSTRUCTOR ---------------------------------
	*/

			explicit vector (const allocator_type& alloc = allocator_type()) : _mem(alloc), _array(0), _capacity(0), _storedElems(0) {}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _mem(alloc), _capacity(n), _storedElems(n)
			{
				_array = _mem.allocate(_capacity);
				for (size_t i = 0; i < _capacity; i++)
					_mem.construct(&_array[i], val);
			}

			template <typename InputIterator>
			vector (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _mem(alloc), _capacity(std::distance(first, last)), _storedElems(_capacity)
			{
				int i = 0;
				_array = _mem.allocate(_capacity);
				while (first != last)
				{
					_mem.construct(&_array[i], *first);
					first++;
					i++;
				}
			}

			vector( vector const & src ) : _array(0), _capacity(0), _storedElems(0) //Not quite sure I like this...
			{
				*this = src;
			}
			
			~vector()
			{
				for (size_t i = 0; i < _storedElems; i++)
					_mem.destroy(&_array[i]); //TODO Might only delete the first element; Test with a class?
				_mem.deallocate(_array, _capacity);
			}

			vector &		operator=( vector const & rhs )
			{
				if (_capacity) //Might not work?
				{
					for (size_t i = 0; i < _storedElems; i++)
						_mem.destroy(&_array[i]);
					_mem.deallocate(_array, _capacity);
				}
				if (rhs._capacity)
				{
					_capacity = rhs._capacity;
					_array = _mem.allocate(_capacity);
					_storedElems = rhs._storedElems;
					for (size_t i = 0; i < _storedElems; i++)
						_mem.construct(&_array[i], rhs._array[i]);
				}
				return (*this);
			}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/
		iterator begin()
		{
			return (_array);
		}

		const_iterator begin() const
		{
			return (_array);
		}

		iterator end()
		{
			return (&_array[_storedElems]);
		}

		const_iterator end() const
		{
			return (&_array[_storedElems]);
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
	** --------------------------------- CAPACITY ----------------------------------
	*/

			size_t size ( void ) const
			{
				return (_storedElems);
			}

			size_type   max_size(void) const
			{
				return _mem.max_size();
			}

			void resize (size_t n, value_type val = value_type()) //Check when smaller not to do stupid things
			{
				while (n < _storedElems)
					pop_back();
				if (n > _capacity)
					reserve(n);
				while (_storedElems != n)
					push_back(val);
			}

			size_t capacity ( void ) const
			{
				return (_capacity);
			}

			bool empty() const
			{
				return (!static_cast <bool> (_storedElems));
			}
		
			void reserve (size_t n)
			{
				value_type		*aux_ptr;

				if (n <= _capacity) //|| n > max_size()) //throw length error
					return ;
				aux_ptr = _mem.allocate(n, _array);
				for (size_t i = 0; i < _storedElems; i++)
					aux_ptr[i] = _array[i];
				if (_array) //Might not be needed
					_mem.deallocate(_array, _capacity);
				_array = aux_ptr;
				_capacity = n;
			}

	/*
	** ------------------------------ ELEMENT ACCESS -------------------------------
	*/

			reference operator[] (size_t n)
			{
				return (_array[n]);
			}
		
			const_reference	operator[] (size_t n) const
			{
				return (_array[n]);
			}
		
			reference at (size_t n)
			{
				if (n >= _storedElems) // check
					throw (std::out_of_range("Because reasons")); //Change!!!!
				return (_array[n]);
			}
		
			const_reference	at(size_t n) const
			{
				if (n >= _capacity)
					throw (std::out_of_range("Because reasons"));
				return (_array[n]);
			}

			reference	front()
			{
				return (_array[0]);
			}

			const_reference	front() const
			{
				return (_array[0]);
			}

			reference	back()
			{
				return (_array[_storedElems - 1]);
			}

			const_reference back() const
			{
				return (_array[_storedElems - 1]);
			}

	/*
	** ------------------------------ MODIFIERS -------------------------------
	*/
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_t aux_size = std::distance(first, last);
				if (aux_size > _capacity)
				{
					for (size_t i = 0; i < _storedElems; i++)
						_mem.destroy(&_array[i]);
					_mem.deallocate(_array, _capacity);
					_capacity = aux_size;
					_array = _mem.allocate(_capacity, _array);
				}
				else 
					clear();
				iterator it = begin();
				while (first != last)
				{
					_mem.construct(&*it, *first);
					first++;
					it++;
				}
				if (_storedElems < aux_size)
					_storedElems = aux_size;
			}

			void assign (size_t n, const_reference val)
			{
				if (n > _capacity)
				{
					for (size_t i = 0; i < _storedElems; i++)
						_mem.destroy(&_array[i]);
					_mem.deallocate(_array, _capacity);
					_capacity = n;
					_array = _mem.allocate(_capacity, _array);
				}
				else
					clear();
				for (size_t i = 0; i < n; i++)
					_mem.construct(&_array[i], val);
				if (_storedElems < n)
					_storedElems = n;
			}

			iterator erase( iterator pos )
			{
				if (pos >= end())
					return (end());
				if (pos < begin())
					pos = begin();
				_mem.destroy(&*pos);
				for (iterator it = pos; it + 1 < end(); it++)
					*it = *(it + 1);
				_storedElems -= 1;
				return (pos);
			}

			iterator erase( iterator first, iterator last )
			{
				if (first > last || first > end() || last > end())
					return (end());
				if (first < begin() && last < begin())
					return (begin());
				if (first < begin())
					first = begin();
				for (iterator it = first; it < last; it++)
					_mem.destroy(&*it);
				for (iterator it = last, it2 = first; it < end(); it++, it2++)
					*it2 = *it;
				_storedElems -= last - first;
				return (first);
			}

			iterator insert(iterator pos, const T& value )
			{
				size_t offset = pos - begin();
				reserve(_storedElems + 1);
				pos = begin() + offset;
				for (iterator it = end(); it > pos; it--)
					*it = *(it - 1);
				_mem.construct(&*pos, value);
				_storedElems += 1;
				return (pos);
			}

			void insert( iterator pos, size_type count, const T& value ) //TODO: Make a function to shift elements left and right?
			{
				size_t offset = pos - begin();
				reserve(_storedElems + count);
				pos = begin() + offset;
				for (iterator it = end() + count - 1; it >= pos + count; it--)
					*it = *(it - count);
				for (iterator aux = pos + count; pos < aux; pos++)
					_mem.construct(&*pos, value);
				_storedElems += count;
				return ;
			}

			template< class InputIterator > //Might need more thingies!
			void insert(iterator pos, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_t offset = pos - begin();
				size_t count = std::distance(first, last);
				reserve(_storedElems + count); //Peta al hacer el reserve, for some reason :(
				pos = begin() + offset;
				for (iterator it = end() + count - 1; it >= pos + count; it--)
					*it = *(it - count);
				for (iterator aux = pos + count; first != last; pos++, first++)
					_mem.construct(&*pos, *first);
				_storedElems += count;
				return ;
			}

			void push_back (const_reference val)
			{
				if (_storedElems < max_size())
				{
					if (_storedElems + 1 > _capacity)
						reserve(_storedElems + 1);
					_mem.construct(&*end(), val);
					_storedElems++;
				}
			}

			void pop_back()
			{
				if (_storedElems)
				{
					_mem.destroy(&back()); //Check
					_storedElems--;
				}
			}


			void clear()
			{
				for (size_t i = 0; i < _storedElems; i++)
					_mem.destroy(&_array[i]);
				_storedElems = 0;
			}

			void swap( vector& other ) //Cplusplus says it checks stuffs and things
			{
				std::swap(_array, other._array);
				std::swap(_storedElems, other._storedElems);
				std::swap(_mem, other._mem);
				std::swap(_capacity, other._capacity);
			}

		protected:
			std::allocator <value_type>	_mem;
			pointer						_array;
			size_t						_capacity;
			size_t						_storedElems;

	};

/*
** ------------------------------ LOGICAL OPERATORS -------------------------------
*/

	template <typename T>
	bool operator==(vector<T> a, vector<T> b)
	{
		if (a.size() != b.size())
				return (false);
		return(equal(a.begin(), a.end(), b.begin(), b.end()));
	}

	template <typename T>
	bool operator!=(vector<T> a, vector<T> b)
	{
		return (!operator==(a, b));
	}

	template <typename T>
	bool operator<(vector<T> a, vector<T> b)
	{
		return (lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()));
	}

	template <typename T>
	bool operator<=(vector<T> a, vector<T> b)
	{
		return (!(b < a));
	}

	template <typename T>
	bool operator>(vector<T> a, vector<T> b)
	{
		return (b < a);
	}

	template <typename T>
	bool operator>=(vector<T> a, vector<T> b)
	{
		return (!(a < b));
	}

	template < class T, class Alloc>
	void swap(ft::vector<T, Alloc> &a, ft::vector<T, Alloc> &b)
	{
		a.swap(b);
	}

}

#endif /* ********************************************************** VECTOR_H */