#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

template <class T> //template < class T, class Alloc = allocator<T
class Vector
{

	public:

		Vector() : mem()
		{
			array = mem.allocate(0);
		}
		Vector( Vector const & src ) : array(0)
		{
			*this = src;
		}
		
		~Vector()
		{
			mem.destroy(array);
			mem.deallocate(array, size);
		}

		Vector &		operator=( Vector const & rhs )
		{
			if (array) //Might not work?
			{
				mem.destroy(array);
				mem.deallocate(array, size);
			}
			size = rhs.size;
			array = mem.allocate(size);
			for (size_t i = 0; i < size; i++)
			{
				array[i] = rhs.array[i];
			}
			return (*this);
		}

	private:
		std::allocator <T>	mem;
		T					*array;
		size_t				size;

};

#endif /* ********************************************************** VECTOR_H */