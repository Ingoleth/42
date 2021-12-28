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
		//typename It::value_type;
		//typename It::pointer;
		//typename It::const_pointer;
		//typename It::reference;
		//typename It::const_reference;
		//typename It::difference_type;
	public:
		ReverseIterator(): It() {}
		ReverseIterator(It const &it): It(it) {}
		ReverseIterator(ReverseIterator const &other): It(other.p) {}

		It base() const
		{
			return (this->p);
		}
		
		ReverseIterator &operator=(ReverseIterator const &other)
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
		bool operator<(ReverseIterator const &other) const
		{
			return (this->It::operator>(other));
		}
		bool operator<=(ReverseIterator const &other) const
		{
			return (this->It::operator>=(other));
		}
		bool operator>(ReverseIterator const &other) const
		{
			return (this->It::operator<(other));
		}
		bool operator>=(ReverseIterator const &other) const
		{
			return (this->It::operator<=(other));
		}

		operator	ReverseIterator<const It>(void) const
		{
			return ReverseIterator<const It>(this->p);
		}

	};
}

#endif