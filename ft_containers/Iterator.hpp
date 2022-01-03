#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template<typename _Tp>
		struct IteratorTrait
		{
			
		};

	// POITNER SPECIALIZATION
	template<typename _Tp>
		class IteratorTrait<_Tp*>
		{
			typedef std::random_access_iterator_tag	iterator_category;
			typedef _Tp								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef _Tp*							pointer;
			typedef _Tp&							reference;
		};
	// CONST SPECIALIZATION
	template<typename _Tp>
		class IteratorTrait<const _Tp*>
		{
			typedef std::random_access_iterator_tag	iterator_category;
			typedef _Tp								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef const _Tp*							pointer;
			typedef const _Tp&							reference;
		};


	template<typename It>
	class ReverseIterator: public It
	{
	public:
	
		typedef std::ptrdiff_t													difference_type;

		ReverseIterator(): It() {}
		ReverseIterator(It const &it) : It(it) {}
		template<class Iter>
		ReverseIterator(ReverseIterator<Iter> const &other) : It(other.base()) {}

		It base() const
		{
			return (this->p);
		}

		typename It::reference operator[](difference_type val)
		{
			return (this->p[-val - 1]);
		}

		typename It::reference operator[](difference_type val) const
		{
			return (this->p[-val - 1]);
		}

		
		ReverseIterator &operator=(It const &other)
		{
			this->p = other.base().base();
			return (*this);
		}

		template<class It2>
		ReverseIterator &operator=(ReverseIterator<It2> const &other)
		{
			this->p = other.base().base();
			return (*this);
		}

		typename It::reference operator*() {
			It tmp(*this);
			return (*--tmp);
		}

		typename It::const_reference operator*() const {
			It tmp(*this);
			return (*--tmp);
		}

		typename It::pointer operator->() {
			It tmp(*this);
			return (&*--tmp);
		}

		typename It::const_pointer operator->() const {
			It tmp(*this);
			return (&*--tmp);
		}

		ReverseIterator operator++(int) {
			ReverseIterator tmp(*this);
			operator++();
			return (tmp);
		}

		ReverseIterator &operator++() {
			this->It::operator--();
			return (*this);
		}

		ReverseIterator operator--(int)
		{
			ReverseIterator tmp(*this);
			operator--();
			return (tmp);
		}

		ReverseIterator &operator--()
		{
			this->It::operator++();
			return (*this);
		}


		/*difference_type	operator-(const ReverseIterator<It>& value) const
		{
			return this->base() + value.base();
		}*/

		ReverseIterator<It> operator-(difference_type const &value) const //Change
		{
			return (ReverseIterator<It>(this->base() + value));
		}

		ReverseIterator<It> &operator-=(difference_type const &value)
		{
			this->p += value;
			return (*this);
		}

		ReverseIterator<It> &operator+=(difference_type const &value)
		{
			this->p -= value;
			return (*this);
		}

		ReverseIterator<It> operator+(int lhs)
		{
			return (ReverseIterator<It>(base() - lhs));
		}

		operator void*()
		{
			return(static_cast<void *> (this->p));
		}

		ReverseIterator<It> operator-(int lhs)
		{
			return (ReverseIterator<It>(base() + lhs));
		}

	};

	template<typename T, typename U>
	bool operator==(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() == b.base());
	}

	template<typename T, typename U>
	bool operator!=(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() != b.base());
	}

	template<typename T, typename U>
	bool operator<(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() > b.base());
	}

	template<typename T, typename U>
	bool operator<=(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() >= b.base());
	}
	template<typename T, typename U>
	bool operator>(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() < b.base());
	}

	template<typename T, typename U>
	bool operator>=(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() <= b.base());
	}

	template<class It>
	ReverseIterator<It> operator+(int lhs, ReverseIterator<It> const &rhs)
	{
		return (ReverseIterator<It>(rhs.base() - lhs));
	}

	template<class It>
	ReverseIterator<It> operator-(int lhs, ReverseIterator<It> const &rhs)
	{
		return (ReverseIterator<It>(rhs.base() + lhs));
	}

	template<class T, class U>
	typename ReverseIterator<T>::difference_type
	operator-(const ReverseIterator<T>& value1, const ReverseIterator<U>& value2)
	{
		return (value2.base() - value1.base());
	}
}

#endif