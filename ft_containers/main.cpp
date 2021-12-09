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

	std::cout << "Vector test:\n";
	ft::vector<int> b(3, 3);
	
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	for(std::vector<int>::reverse_iterator it = a.rbegin(); it < a.rend(); it++)
		std::cout << *it << std::endl;

	for (ft::vector<int>::reverse_iterator it = b.rbegin(); it < b.rend(); it++)
		std::cout << *it << std::endl;

	return 0;
}
