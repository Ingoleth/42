#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>
# include "../vector.hpp"
# include "../stack.hpp"
# include "../map.hpp"

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# define GOOD "✓"
# define FAIL "❌"
# define MARGIN 120

void	test_vector(void);
void	test_list(void);
void	test_map(void);
void	test_stack(void);
void	test_queue(void);

inline void print_header(std::string str)
{
	int margin = (MARGIN + 2 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << BLUE << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << RESET;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(MARGIN - name.length(), ' ');
	if (a == b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(MARGIN - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	/*std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << a.empty() << std::endl;
	std::cout << b.empty() << std::endl;*/
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

/*template <typename T>
bool operator==(ft::List<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::List<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::Map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::Map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};*/

#endif