//#include "Vector.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "BinaryTree.hpp"
#include <map>
#include "tests/tests.hpp"

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
	//ft::vector<std::string> v1;

	//v1.resize(10, "test");
	test_vector();
	//for (ft::vector<std::string>::iterator it = v1.begin(); it < v1.end(); it++)
	//	std::cout << *it << std::endl;
	return 0;
}

