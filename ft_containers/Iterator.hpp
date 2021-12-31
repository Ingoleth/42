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
		ReverseIterator(const void *p) : It(p) {}
		ReverseIterator(ReverseIterator const &other) : It(other.p) {}

		It base() const
		{
			return (this->p);
		}
		
		ReverseIterator &operator=(ReverseIterator<const It> const &other)
		{
			this->p = other.p;
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

		It &operator++() {
			return (this->It::operator--());
		}

		ReverseIterator operator--(int)
		{
			ReverseIterator tmp(*this);
			operator--();
			return (tmp);
		}

		It &operator--()
		{
			return (this->It::operator++());
		}

		difference_type	operator-(const ReverseIterator<It>& value) const
		{
			return this->base() + value.base();
		}

		ReverseIterator<It> operator-(difference_type value) const //Change
		{
			return (ReverseIterator<It>(this->base() + value));
		}

		ReverseIterator<It> &operator-=(difference_type value)
		{
			this->p += value;
			return (*this);
		}

		ReverseIterator<It> &operator+=(difference_type value)
		{
			this->p -= value;
			return (*this);
		}

/*		template <typename T>
		operator VectorIterator<const T>()
		{
			return(VectorIterator<T>(this->p));
		}*/

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
		return (a.base() < b.base());
	}

	template<typename T, typename U>
	bool operator<=(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() <= b.base());
	}
	template<typename T, typename U>
	bool operator>(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() > b.base());
	}

	template<typename T, typename U>
	bool operator>=(ReverseIterator<T> const &a, ReverseIterator<U> const &b)
	{
		return (a.base() >= b.base());
	}

	template<class It>
	ReverseIterator<It> operator+(int lhs, ReverseIterator<It> rhs)
	{
		return (ReverseIterator<It>(rhs.base() - lhs));
	}
}

#endif