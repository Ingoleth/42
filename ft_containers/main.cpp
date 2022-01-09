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
	ft::BTNode<int> *root = new ft::BTNode<int>();

	root->data = 2;
	/*for (size_t i = 1; i < 5; i++)
	{
		root->add(i, root);
	}*/
	root->add(4, root);
	root->add(3, root);
	root->add(1, root);
	root->add(5, root);


	//root->remove(2, root);

	root->displayInOrder(root);

	
	return 0;
}

