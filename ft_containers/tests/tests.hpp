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

# define GOOD "✅"
# define FAIL "❌"
# define MARGIN 85
# define TEST_SIZE 1000000

void	test_vector(void);
void	test_map(void);
void	test_stack(void);
void	test_exec_time();
void	test_leaks();

inline void print_header(std::string str, bool green = false)
{
	int margin = (MARGIN - str.length()) / 2;
	std::cout << (green ? GREEN : BLUE);
	if (green)
		std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::string(margin, '-') << ' ' << str << ' ' << std::string(margin, '-') << std::endl;
	std::cout << std::endl;
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

#endif