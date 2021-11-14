#ifndef ARRAY
#define ARRAY

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:

		Array() : _array(0), _size(0) {}

		Array(int n) : _size(n)
		{
			_array = new T[n];
		}

		Array( Array const & src ) : _array(0) {*this = src;}

		~Array(){ delete[] _array;}

		Array &operator=( Array const & rhs )
		{
			if (_array)
				delete[] _array;
			_size = rhs._size;
			if (_size)
			{
				_array = new T[_size];
				for (int i = 0; i < _size; i++)
				{
					_array[i] = rhs[i];
				}
			}
			else
				_array = 0;
			return (*this);
		}
		
        T &operator[](int idx)
		{
			if (idx < 0 || idx >= _size)
				throw std::out_of_range("Invalid index; Index is out of range");
			return _array[idx];
		}

		T operator[](int idx) const
		{
			if (idx < 0 || idx >= _size)
				throw std::out_of_range("Invalid index; Index is out of range");
			return _array[idx];
		}

		int size() const
		{
			return (_size);
		}

	private:
		int	_size;
		T		*_array;
};

//std::ostream &			operator<<( std::ostream & o, Array const & i );
#endif