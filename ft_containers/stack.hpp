#ifndef STACK_HPP
# define STACK_HPP
#include "vector.hpp"

namespace ft
{
	template < class T, class _Sequence = vector<T> >
	class stack
	{
	public:

		
		typedef typename    _Sequence::value_type		value_type;
		typedef typename    _Sequence::reference		reference;
		typedef typename    _Sequence::const_reference	const_reference;
		typedef typename    _Sequence::size_type        size_type;
		typedef             _Sequence                   container_type;
		
		//explicit stack () : data(){};

		explicit stack(const container_type &src = container_type()) : data(src) {};

			  ~stack() {};

		bool empty() const
		{
			return(data.empty());
		}

		size_type size() const
		{
			return(data.size());
		}

		reference top()
		{
			return(data.back());
		}

		const_reference top() const
		{
			return(data.back());
		}

		void push (const_reference val)
		{
			data.push_back(val);
		}

		void pop()
		{
			data.pop_back();
		}

	template <class Tn, class _SequenceN>
	friend bool operator==(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

	template <class Tn, class _SequenceN>
	friend	bool operator!=(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

	template <class Tn, class _SequenceN>
	friend	bool operator<(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

	template <class Tn, class _SequenceN>
	friend	bool operator>(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

	template <class Tn, class _SequenceN>
	friend	bool operator>=(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

	template <class Tn, class _SequenceN>
	friend	bool operator<=(const stack <Tn, _SequenceN> &a, const stack <Tn, _SequenceN> &b);

		protected:
			container_type data;
	};

	template <class T,  class _Sequence>
	 bool operator==(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return(a.data == b.data);
		}

	template <class T,  class _Sequence>
	bool operator!=(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return (a.data != b.data);
		}

	template <class T,  class _Sequence>
	bool operator<(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return (a.data < b.data);
		}

	template <class T,  class _Sequence>
	bool operator>(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return (a.data > b.data);
		}

	template <class T,  class _Sequence>
	bool operator>=(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return (a.data >= b.data);
		}

	template <class T,  class _Sequence>
	bool operator<=(const stack <T, _Sequence> &a, const stack <T, _Sequence> &b)
		{
			return (a.data <= b.data);
		}
}

#endif
