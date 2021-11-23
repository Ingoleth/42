#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

template <class T> //template < class T, class Alloc = allocator<T
class Vector
{

	public:

		Vector() : mem(), _storedElems(0), _allocMem (1)
		{
			array = mem.allocate(1);
		}

		Vector( Vector const & src ) : _array(0)
		{
			*this = src;
		}
		
		~Vector()
		{
			mem.destroy(_array); //TODO Might only delete the first element; Test with a class?
			mem.deallocate(_array, _allocMem);
		}

		Vector &		operator=( Vector const & rhs )
		{
			if (array) //Might not work?
			{
				mem.destroy(array);
				mem.deallocate(array, _allocMem);
				std::cout << "Hello\n";
			}
			if (rhs._array)
			{
				_allocMem = rhs._allocMem;
				_array = _mem.allocate(_allocMem);
				for (size_t i = 0; i < _storedeElems; i++)
				{
					_array[i] = rhs._array[i];
				}
			}
			return (*this);
		}

	private:
		std::allocator <T>	_mem;
		T					*_array;
		size_t				_allocMem;
		size_t				_storedElems;

};

#endif /* ********************************************************** VECTOR_H */