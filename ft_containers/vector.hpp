#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "utils.hpp"
# include "Iterator.hpp"
# include <limits>

namespace ft
{

	template<typename T>
	class VectorIterator: IteratorTrait
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
	
	public:
		pointer p;
		VectorIterator(): p(0) {}

		VectorIterator(pointer p): p(p) {}

		VectorIterator(VectorIterator const &src): p(src.p) {}

		virtual ~VectorIterator() {}

		VectorIterator &operator=(VectorIterator const &src) {
			this->p = src.p;
			return (*this);
		}

		reference operator*() {
			return (*this->p);
		}
		const_reference operator*() const {
			return (*this->p);
		}
		pointer operator->() {
			return (this->p);
		}
		const_pointer operator->() const {
			return (this->p);
		}
		reference operator[](int val) {
			return (*(this->p + val));
		}
		const_reference operator[](int val) const {
			return (*(this->p + val));
		}

		VectorIterator operator++(int) {
			VectorIterator tmp(*this);
			++this->p;
			return (tmp);
		}
		VectorIterator &operator++() {
			++this->p;
			return (*this);
		}
		VectorIterator operator--(int) {
			VectorIterator tmp(*this);
			--this->p;
			return (tmp);
		}
		VectorIterator &operator--() {
			--this->p;
			return (*this);
		}

		VectorIterator &operator+=(int value) {
			this->p += value;
			return (*this);
		}
		VectorIterator operator+(int value) const {
			VectorIterator tmp(*this);
			return (tmp += value);
		}
		VectorIterator &operator-=(int value) {
			this->p -= value;
			return (*this);
		}
		VectorIterator operator-(int value) const {
			VectorIterator tmp(*this);
			return (tmp -= value);
		}
		difference_type operator-(VectorIterator const &src) const {
			return (this->p - src.p);
		}

		bool operator==(VectorIterator const &src) const {
			return (this->p == src.p);
		}
		bool operator!=(VectorIterator const &src) const {
			return (this->p != src.p);
		}
		bool operator<(VectorIterator const &src) const {
			return (this->p < src.p);
		}
		bool operator<=(VectorIterator const &src) const {
			return (this->p <= src.p);
		}
		bool operator>(VectorIterator const &src) const {
			return (this->p > src.p);
		}
		bool operator>=(VectorIterator const &src) const {
			return (this->p >= src.p);
		}
	};

	template<typename T>
	std::ostream &			operator<<( std::ostream & o, VectorIterator<T> const & i )
{
	o << i.p;
	return o;
}

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		friend void swap(vector<T>a, vector<T> b);

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

			explicit vector (const allocator_type& alloc = allocator_type()) : _mem(alloc), _capacity(1), _storedElems(0)
			{
				_array = _mem.allocate(1 * sizeof(value_type));
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _mem(alloc), _capacity(1), _storedElems(0)
			{
				while (_capacity < n)
					_capacity *= 2;
				_array = _mem.allocate(_capacity * sizeof(value_type));
				for (size_t i = 0; i < _capacity; i++)
					_mem.construct(&_array[i], val);
				_storedElems = n;
			}

			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<is_convertible<typename InputIterator::iterator_category, std::input_iterator_tag>::value, void>::type* = NULL)
			: _storedElems(std::distance(first, last)), _capacity(_storedElems), _mem(alloc)
			{
				int i = 0;
				_array = _mem.allocate(_capacity * sizeof(value_type));
				while (first != last)
				{
					_mem.construct(&_array[i], *first);
					first++;
					i++;
				}
			}

			vector( vector const & src ) : _array(0)
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
				if (_array) //Might not work?
				{
					for (size_t i = 0; i < _storedElems; i++)
						_mem.destroy(&_array[i]);
					_mem.deallocate(_array, _capacity);
				}
				if (rhs._array)
				{
					_capacity = rhs._capacity;
					_array = _mem.allocate(_capacity * sizeof(value_type));
					_storedElems = rhs._storedElems;
					for (size_t i = 0; i < _storedElems; i++)
						_array[i] = rhs._array[i];
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

			size_t max_size( void ) const
			{
				return(std::numeric_limits<size_type>::max() / sizeof(value_type));
			}

			void resize (size_t n, value_type val = value_type()) //Check when smaller not to do stupid things
			{
				while (n > _storedElems)
					pop_back();
				if (n < _capacity)
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
				return (static_cast <bool> (_storedElems));
			}
		
			void reserve (size_t n)
			{
				value_type		*aux_ptr;

				if (n <= _capacity) //|| n > max_size()) //throw length error
					return ;
				aux_ptr = _mem.allocate(n, _array);
				for (size_t i = 0; i < _storedElems; i++)
				{
					aux_ptr[i] = _array[i];
					_mem.destroy(&_array[i]);
				}
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
					throw (std::out_of_range("Because reasons"));
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
			void	assign(InputIterator first, InputIterator last, typename enable_if<is_convertible<typename InputIterator::iterator_category, std::input_iterator_tag>::value, void>::type* = NULL)
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
				clear();
				for (size_t i = 0; i < n; i++)
					_mem.construct(&_array[i], val);
				if (_storedElems < n)
					_storedElems = n;
			}

			iterator erase( iterator pos )
			{
				if (pos <= end())
					return (end);
				if (pos < begin())
					pos = begin();
				_mem.destroy(&*pos);
				for (iterator it = pos; it + 1 < end(); it++)
				{
					_mem.construct(&*(it), *(it + 1));
					_mem.destroy(&*(it + 1));
				}
				_storedElems += 1;
				return (pos + 1);
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
				{
					_mem.construct(&*(it2), *(it));
					_mem.destroy(&*(it));
				}
				_storedElems -= last - first;
				return (last);
			}

			iterator insert(iterator pos, const T& value )
			{
				if (pos >= end())
					return (end());
				if (pos < begin())
					return (begin());
				size_t offset = pos - begin();
				reserve(_storedElems + 1);
				pos = begin() + offset;
				for (iterator it = end(); it > pos; it--)
				{
					_mem.construct(&*(it), *(it - 1));
					_mem.destroy(&*(it - 1));
				}
				_mem.construct(&*pos, value);
				_storedElems += 1;
				return (pos + 1);
			}

			void insert( iterator pos, size_type count, const T& value ) //TODO: Make a function to shift elements left and right?
			{
				if (pos >= end())
					return ;
				if (pos < begin())
					return ;
				size_t offset = pos - begin();
				reserve(_storedElems + 1);
				pos = begin() + offset;
				for (iterator it = end() + count; it >= pos + count; it--)
				{
					_mem.construct(&*(it), *(it - count));
					_mem.destroy(&*(it - count));
				}
				for (iterator aux = pos + count; pos < aux; pos++)
					_mem.construct(&*pos, value);
				_storedElems += count;
				return ;
			}

			template< class InputIt > //Might need more thingies!
			void insert( iterator pos, InputIt first, InputIt last )
			{
				if (pos >= end())
					return ;
				if (pos < begin())
					return ;
				size_t offset = pos - begin();
				reserve(_storedElems + 1);
				pos = begin() + offset;
				size_t count = std::distance(first, last);
				for (iterator it = end() + count; it >= pos + count; it--)
				{
					_mem.construct(&*(it), *(it - count));
					_mem.destroy(&*(it - count));
				}
				for (iterator aux = pos + count; first < last; pos++, first++)
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

			void swap( vector& other )
			{
				pointer aux;

				aux =_array;
				_array = other._array;
				other._array = aux;
			}

		protected:
			std::allocator <value_type>	_mem;
			pointer				_array;
			size_t				_capacity;
			size_t				_storedElems;

	};

	template<typename T>
	void swap(vector<T>a, vector<T> b)
	{
		std::swap(a._array, b._array);
		std::swap(a._capacity, b._capacity);
		std::swap(a._storedElems, b._storedElems);
	}

	/*
** ------------------------------ LOGICAL OPERATORS -------------------------------
*/

	template <typename T>
	bool operator==(vector<T> a, vector<T> b)
	{
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
	bool operator>(vector<T> a, vector<T> b)
	{
		return (!operator<(a, b));
	}

	template <typename T>
	bool operator>=(vector<T> a, vector<T> b)
	{
		return (!operator<(a, b) || operator==(a, b));
	}

	template <typename T>
	bool operator<=(vector<T> a, vector<T> b)
	{
		return (!operator<(a, b) || operator==(a, b));
	}

}




#endif /* ********************************************************** VECTOR_H */