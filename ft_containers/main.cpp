#include "Vector.hpp"
#include <vector>
#include <iostream>

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
	
	Vector <test> a;
	std::vector<test> v;

	std::cout << "Vector test:\n";


	test c;
	std::cout << "ft_Vector test:\n";
	a.assign(10, c);
	std::cout << a.back();
	a.pop_back();

	return 0;
}
