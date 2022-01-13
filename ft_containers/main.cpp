#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "BinaryTree.hpp"
#include "map.hpp"
#include <map>
#include "tests/tests.hpp"
#include <string>

class test
{
private:
	/* data */
public:
	test(/* args */);
	test(test &src)
	{
		std::cout << "I have been created via copy! " << src.getValue() << std::endl;
	}
	~test();
	int getValue( void ) const
	{
		return (0);
	}
};

test::test(/* args */)
{
	std::cout << "I have been created\n";
}

test::~test()
{
	std::cout << "I have been destroyed\n";
}

std::ostream &			operator<<( std::ostream & o, test const & i )
{
	o << "hello " << i.getValue() << "\n";
	return o;
}

int main()
{
	ft::map<int, std::string> map;
	ft::map<int, std::string> map2;
	ft::pair<int, std::string> a = ft::make_pair(0, "Hey listen!");
	ft::pair<int, std::string> b = ft::make_pair(1, "Hello");
	ft::pair<int, std::string> c = ft::make_pair(2, "Goodbye");
	
	map2.insert(a);
	map2.insert(b);
	map2.insert(c);
	map2.insert(c);
	map.insert(map2.begin(), --map2.end());
	map.insert(--map.end(), c);

	for (ft::map<int, std::string>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	
	return 0;
}