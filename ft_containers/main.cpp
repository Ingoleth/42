//#include "Vector.hpp"
#include <vector>
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
	
	std::vector <int> a;

	a.reserve(5);
	a.push_back(1);
	a.push_back(2);

	std::cout << a.capacity() << std::endl;
	std::cout << a.size() << std::endl;
	a.push_back(3);
	std::cout << a.back() << std::endl;
	std::cout << a[a.size() - 1] << std::endl;
	std::cout << a[a.capacity() - 1] << std::endl;

	std::cout << "Vector test:\n";


	return 0;
}
