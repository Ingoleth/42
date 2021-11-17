
#include "easyfind.hpp"
#include <string>
#include <iostream>
#include <vector>

int main( void )
{
std::vector<int> v;
v.push_back(1);

try
{
	int i = *(easyfind(v, 1));
	std::cout << i << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}
std::vector<int> v2;
try
{
	int i = *(easyfind(v2, 1));
	std::cout << i << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}	
return 0;
}
