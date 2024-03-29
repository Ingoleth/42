# ifndef CONTAINERS_UTILS
# define CONTAINERS_UTILS

#include <iostream>

//template <typename T>
//static const bool is_integer;
namespace ft
{

	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>
	{ 
		typedef T type;
	};

	template <class T, T val>
		struct integral_constant {
			static	const T value = val;
			typedef	T value_type;
			typedef	integral_constant<T, val> type;
			operator value_type() { return val; }
	};

	//Most longwinded way of saying const bool IN HISTORY
	//Should be banned by law
	struct true_type : public integral_constant<bool,true>
	{
		typedef true_type	type;
	};

	struct false_type : public integral_constant<bool,false>
	{
		typedef false_type	type;
	};
	// typedef integral_constant<bool,true> true_type;
	// typedef integral_constant<bool,false> false_type;


	template<typename T>
		struct is_integral : public false_type {};
	template <>
		struct is_integral<bool> : public true_type {};
	template <>
		struct is_integral<char> : public true_type {};
	template <>
		struct is_integral<int> : public true_type {};
	template <>
		struct is_integral<long int> : public true_type {};
	//and so on...

	template<typename T> //FIXME: creo que no lo utilizo
	struct	has_iterator_category
	{
		typedef char yes[1];
		typedef char no[2];

		template<typename C>
		static yes & test(typename C::iterator_category *);
		
		template<typename C>
		static no & test(...);

		static const bool value = sizeof(test<T>(NULL)) == sizeof(yes);
	};

	template < class From, class To >
		struct is_convertible_simple
		{
			typedef char yes[1];
			typedef char no[2];

			static yes & test(To);
			static no & test(...);
			static From returnFrom();

			static const bool value = (sizeof(test(returnFrom())) == sizeof(yes));
		};

	template < class From, class To >
		struct is_convertible
		: public integral_constant<bool, is_convertible_simple<From, To>::value> 
		{ };

	/*
	** --------------------------------- PAIR ----------------------------------
	*/

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(): first(first_type()), second(second_type()) {}

		pair (const pair<T1,T2>& pr): //Might not be needed?
			first(pr.first),
			second(pr.second) {}

		
		template <class U1, class U2>
		pair (const std::pair<U1,U2>& pr):
			first(pr.first),
			second(pr.second) {}

		template <class U, class V> 
			pair (const pair<U,V>& pr):
				first(pr.first),
				second(pr.second) {}
	
		// initialization
		pair (const first_type& a, const second_type& b): first(first_type(a)), second(second_type(b)) {}

		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
			return (*this);
		}

		operator std::pair<first_type, second_type>() const
		{
			return std::make_pair(first, second);
		}

	};

		template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first == rhs.first && lhs.second == rhs.second; }

		template <class T1, class T2>
		bool operator== (const ft::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
		{ return lhs.first == rhs.first && lhs.second == rhs.second; }

		template <class T1, class T2>
		bool operator== (const std::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
		{ return lhs.first == rhs.first && lhs.second == rhs.second; }

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs == rhs); }
	
	template <class T1, class T2>
		bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs < lhs); }

	template <class T1, class T2>
		bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs < lhs; }

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs < rhs); }

	template <typename T1, typename T2>
	std::ostream &operator<<( std::ostream & o, const pair<T1, T2> &p)
	{
		o << p.first << " " << p.second;
		return o;
	}

	template <class T1, class T2>
	ft::pair <T1, T2> make_pair(T1 first, T2 second)
	{
		return (ft::pair<T1, T2>(first, second));
	}

	/*
	** --------------------------------- EQUALS ----------------------------------
	*/

	template <class InputIterator1, class InputIterator2>
		bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			while (first1 != last1)
			{
				if (!(*first1 == *first2))
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
		{
			while (first1 != last1)
			{
				if (!pred(*first1, *first2))
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

	/*
	** --------------------------------- LEXICOGRAPHICAL ----------------------------------
	*/

	template< class InputIt1, class InputIt2 > // Is iterator check?
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<typename _Tp>
    struct greater : public std::binary_function<_Tp, _Tp, bool>
    {
    	bool operator()(const _Tp& __x, const _Tp& __y) const
		{
			return __y < __x;
		}
    };


}

# endif