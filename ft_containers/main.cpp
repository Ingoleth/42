//#include "Vector.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
#include "BinaryTree.hpp"
#include <map>

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

void printSize(TESTED_NAMESPACE::vector<TESTED_TYPE>& a)
{
	std::cout << a.size() << std::endl;
}

int main()
{

	using namespace ft;

	vector<int> a;
	vector<int> b;

	a.push_back(1);
	a.push_back(3);
	a.push_back(4);

	b = a;

	b.push_back(5);
	a.push_back(0);

	a.insert(a.begin(), b.begin(), b.end());

	for (vector<int>::iterator it = a.begin(); it < a.end(); it++)
		std::cout << *it << " ";

	std::cout << "\n";

	return 0;
}
