//#include "Vector.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "stack.hpp"
#include "Vector.hpp"
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

int main()
{
	ft::BTNode<int> *a;

	a = new ft::BTNode<int>(10);
	a->add(13, a);
	a->add(9, a);
	a->add(16, a);
	std::cout <<  a->findSmallest(a)->data << std::endl;
	std::cout << a->findBiggest(a)->data << std::endl;
	return 0;
}
