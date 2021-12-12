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