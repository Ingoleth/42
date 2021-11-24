#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

template <class T> //template < class T, class Alloc = allocator<T
class Vector
{

	public:

		Vector() : _mem(), _allocMem (1), _storedElems(0)
		{
			_array = _mem.allocate(1 * sizeof(T));
		}

		Vector( Vector const & src ) : _array(0)
		{
			*this = src;
		}
		
		~Vector()
		{
			_mem.destroy(_array); //TODO Might only delete the first element; Test with a class?
			_mem.deallocate(_array, _allocMem);
		}

		Vector &		operator=( Vector const & rhs )
		{
			if (_array) //Might not work?
			{
				_mem.destroy(_array);
				_mem.deallocate(_array, _allocMem);
				std::cout << "Hello\n";
			}
			if (rhs._array)
			{
				_allocMem = rhs._allocMem;
				_array = _mem.allocate(_allocMem * sizeof(T));
				for (size_t i = 0; i < _storedElems; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}

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
			aux_size = _allocMem;
			aux_ptr = _mem.allocate(aux_size);
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
			_mem.deallocate(_array, _allocMem);
			_array = aux_ptr;
			_allocMem = aux_size;
			_storedElems = n;
		}

		size_t capacity ( void ) const
		{
			return (_allocMem);
		}

		bool empty() const
		{
			return (static_cast <bool> (_storedElems));
		}
	
		void reserve (size_t n)
		{
			T		*aux_ptr;

			if (n < _allocMem) //|| n > max_size()) //throw length error
				return ;
			aux_ptr = _mem.allocate(n);
			for (size_t i = 0; i < _storedElems; i++)
				aux_ptr[i] = _array[i];
			_mem.deallocate(_array, _allocMem);
			_array = aux_ptr;
			_allocMem = n;
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
			if (n >= _allocMem)
				throw (std::out_of_range("Because reasons"));
			return (_array[n]);
		}
	
		const T	&at (size_t n) const
		{
			if (n >= _allocMem)
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
			return (_array[_allocMem - 1]);
		}

		const T&back() const
		{
			return (_array[_allocMem - 1]);
		}



		/*void assign (InputIterator first, InputIterator last) //ask garrafa about them templates
		{
			size_t aux_size = last - first - 1;
			if (aux_size > _allocMem)
				reserve(aux_size);
			for (InputIterator i = first, InputIterator j = begin(); i < last; i++, j++)
				j = i;
		}*/
		void assign (size_t n, const T& val) //TODO check if n <?
		{
			if (n > _allocMem)
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
			if (_storedElems + 1 > _allocMem)
				reserve(_storedElems + 1);
			back() = val;
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
		T					*_array;
		size_t				_allocMem;
		size_t				_storedElems;

};




#endif /* ********************************************************** VECTOR_H */