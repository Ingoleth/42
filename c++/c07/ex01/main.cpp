
#include "iter.hpp"
#include <string>
#include <iostream>

int main( void )
{
	int a[3];

	a[0] = 0;
	a[1] = 1;
	a[2] = 2;

	std::string b[2];
	b[0] = "hello";
	b[1] = "world";

	::iter(a, 3, ::list);
	::iter(a, 3, ::increment);
	::iter(a, 3, ::list);

	::iter(b, 2, ::list);
	
return 0;
}
