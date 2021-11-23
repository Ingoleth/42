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
				if (val)
				{
					for (size_t i = _storedElems; i < n; i++)
						aux_ptr[i] = T(val); //Might petar;
				}
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

	private:
		std::allocator <T>	_mem;
		T					*_array;
		size_t				_allocMem;
		size_t				_storedElems;

};

#endif /* ********************************************************** VECTOR_H */