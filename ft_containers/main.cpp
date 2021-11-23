#include "Vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	
	Vector <int> a;

	std::vector<int> v;
	v.reserve(5);
	std::cout << v.capacity() << std::endl;
	v.resize(10);
	v.front() = 5;
	std::cout << v.capacity() << std::endl;
	std::cout << v.front() << std::endl;
	
	a.reserve(5);
	std::cout << a.capacity() << std::endl;
	a.resize(10);
	a.front() = 5;
	std::cout << a.capacity() << std::endl;
	std::cout << a.front() << std::endl;
	return 0;
}
