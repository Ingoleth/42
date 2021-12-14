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