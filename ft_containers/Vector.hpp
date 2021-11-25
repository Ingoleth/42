#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{

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
			typedef ft::random_access_iterator<value_type>						iterator;
			typedef ft::random_access_iterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; 
			typedef typename allocator_type::size_type							size_type;

			vector() : _mem(), _capacity(1), _storedElems(0)
			{
				_array = _mem.allocate(1 * sizeof(T));
			}

			vector( vector const & src ) : _array(0)
			{
				*this = src;
			}
			
			~vector()
			{
				_mem.destroy(_array); //TODO Might only delete the first element; Test with a class?
				_mem.deallocate(_array, _capacity);
			}

			vector &		operator=( vector const & rhs )
			{
				if (_array) //Might not work?
				{
					_mem.destroy(_array);
					_mem.deallocate(_array, _capacity);
					std::cout << "Hello\n";
				}
				if (rhs._array)
				{
					_capacity = rhs._capacity;
					_array = _mem.allocate(_capacity * sizeof(T));
					for (size_t i = 0; i < _storedElems; i++)
						_array[i] = rhs._array[i];
				}
				return (*this);
			}

	/*									 
	** --------------------------------- ITERATORS ----------------------------------
	*/

	/*									 
	** --------------------------------- CAPACITY ----------------------------------
	*/

			size_t size ( void ) const
			{
				return (_storedElems);
			}

			size_t max_size( void ) const
			{
				return (0);//return (INT_MAX / sizeof(T));
			}

			void resize (size_t n, T val = T())
			{
				T *aux_ptr;
				size_t aux_size;

				//|| n > max_size()) //throw length error
				aux_size = _capacity;
				aux_ptr = _mem.allocate(aux_size, _array);
				if (_storedElems > n)
				{
					while (aux_size / 2 > n)
						aux_size /= 2; //Might petar?
					for (size_t i = 0; i < n; i++)
						aux_ptr[i] = _array[i];
				}
				else
				{
					while (aux_size < n)
						aux_size *= 2;
					for (size_t i = 0; i < _storedElems; i++)
						aux_ptr[i] = _array[i];
					for (size_t i = _storedElems; i < n; i++)
						aux_ptr[i] = T(val); //Might petar;
				}
				_mem.deallocate(_array, _capacity);
				_array = aux_ptr;
				_capacity = aux_size;
				_storedElems = n;
			}

			size_t capacity ( void ) const
			{
				return (_capacity);
			}

			bool empty() const
			{
				return (static_cast <bool> (_storedElems));
			}
		
			void reserve (size_t n)
			{
				T		*aux_ptr;

				if (n < _capacity) //|| n > max_size()) //throw length error
					return ;
				aux_ptr = _mem.allocate(n, _array);
				for (size_t i = 0; i < _storedElems; i++)
					aux_ptr[i] = _array[i];
				_mem.deallocate(_array, _capacity);
				_array = aux_ptr;
				_capacity = n;
			}

	/*
	** ------------------------------ ELEMENT ACCESS -------------------------------
	*/

			T &operator[] (size_t n)
			{
				return (_array[n]);
			}
		
			const T	&operator[] (size_t n) const
			{
				return (_array[n]);
			}
		
			T &at (size_t n)
			{
				if (n >= _capacity)
					throw (std::out_of_range("Because reasons"));
				return (_array[n]);
			}
		
			const T	&at (size_t n) const
			{
				if (n >= _capacity)
					throw (std::out_of_range("Because reasons"));
				return (_array[n]);
			}

			T &front()
			{
				return (_array[0]);
			}

			const T &front() const
			{
				return (_array[0]);
			}

			T &back()
			{
				return (_array[_capacity - 1]);
			}

			const T&back() const
			{
				return (_array[_capacity - 1]);
			}

	/*
	** ------------------------------ MODIFIERS -------------------------------
	*/

			void assign (std::iterator <T> first, std::iterator last) //ask garrafa about them templates
			{
				size_t aux_size = last - first - 1;
				if (aux_size > _capacity)
					reserve(aux_size);
				for (std::iterator <T> i = first, std::iterator <T> j = begin(); i < last; i++, j++)
					j = i;
			}

			void assign (size_t n, const T& val) //TODO check if n <?
			{
				if (n > _capacity)
					reserve(n);
				std::cout << "Hello there!\n";
				for (size_t i = 0; i < n; i++)
				{
					std::cout << i << std::endl;
					_array[n] = val;
				}
			}

			void push_back (const T& val)
			{
				if (_storedElems + 1 > _capacity)
					reserve(_storedElems + 1);
				_mem.construct(&back(), val);
			}

			void pop_back()
			{
				_mem.destroy(&back(), 1); //Check
				_storedElems--;
			}


			void clear() //Iterator invalidation? -->     std::cout << "After clear:"; std::for_each(container.begin(), container.end(), print); -> No outputea nada
			{
				_mem.destroy(_array, _storedElems);
				_storedElems = 0;
			}

		private:
			std::allocator <T>	_mem;
			pointer				_array;
			size_t				_capacity;
			size_t				_storedElems;

	};

}




#endif /* ********************************************************** VECTOR_H */