#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "BinaryTree.hpp"
#include "Map.hpp"
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
	ft::pair<int, std::string> a = ft::make_pair(0, "Hey listen!");
	ft::pair<int, std::string> b = ft::make_pair(1, "Hello");
	ft::pair<int, std::string> c = ft::make_pair(2, "Goodbye");
	
	map.insert(a);
	map.insert(b);
	map.insert(c);
	map.insert(c);
	map.debugMap();
	ft::map<int, std::string>::iterator it = map.begin();
	std::cout << it->second << std::endl;
	
	return 0;
}