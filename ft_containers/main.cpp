//#include "Vector.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "Vector.hpp"

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
	ft::vector<int>a;
	ft::vector<int>b;

	std::cout << (a < b) << std::endl;
	std::cout << (b < a) << std::endl;	

	return 0;
}
