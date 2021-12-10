#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	struct IteratorTrait{};

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
		ReverseIterator operator--(int) {
			ReverseIterator tmp(*this);
			operator--();
			return (tmp);
		}
		It &operator--() {
			return (this->It::operator++());
		}
		bool operator<(ReverseIterator const &other) const {
			return (this->It::operator>(other));
		}
		bool operator<=(ReverseIterator const &other) const {
			return (this->It::operator>=(other));
		}
		bool operator>(ReverseIterator const &other) const {
			return (this->It::operator<(other));
		}
		bool operator>=(ReverseIterator const &other) const {
			return (this->It::operator<=(other));
		}
	};
}

#endif