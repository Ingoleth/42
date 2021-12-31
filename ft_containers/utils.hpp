# ifndef CONTAINERS_UTILS
# define CONTAINERS_UTILS

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
	struct	has_iterator_category {
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

		pair() : first(), second() {}

		pair(first_type &_first, second_type &_second) : first(_first), second(_second) {}
	
		pair(const first_type &_first, const second_type &_second) : first(_first), second(_second) {}
	
		template<typename U1, typename U2>
		pair(const pair <U1, U2> p) : first(p.first), second(p.first) {}
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &a, const pair<T1, T2> &b)
	{
		return (a.first == b.second && a.second == b.second);
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &a, const pair<T1, T2> &b)
	{
		return (a.first < b.first && a.second < b.second);
	}
	
	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &a, const pair<T1, T2> &b)
	{
		return (!(a == b));
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &a, const pair<T1, T2> &b)
	{
		return (a == b || a < b);
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &a, const pair<T1, T2> &b)
	{
		return (a == b || a > b);
	}

	template <typename T1, typename T2>
	pair <T1, T2> &make_pair(T1 first, T2 second)
	{
		return (pair<T1, T2>(first, second));
	}

	/*
	** --------------------------------- EQUALS ----------------------------------
	*/

	template< class InputIt1, class InputIt2 > // Is iterator check?
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		while (first1 != last1)
		{
			if (first2 == last2)
				return (false);
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (first2 == last2);
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
}

# endif