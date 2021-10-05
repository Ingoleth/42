#include <iostream>
#include <bitset>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	float a_f = a.toFloat();
	float b_f = b.toFloat();

	std::cout << "\n----------------\nAritmethic tests\n----------------\n";
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl << std::endl;
	std::cout << "A + B = " << a + b << std::endl;
	std::cout << "A + B = " << a_f + b_f << "f" << std::endl << std::endl;
	std::cout << "A - B = " << a - b << std::endl;
	std::cout << "A - B = " << a_f - b_f << "f" << std::endl << std::endl;
	std::cout << "A * B = " << a * b << std::endl;
	std::cout << "A * B = " << a_f * b_f << "f" << std::endl << std::endl;
	std::cout << "A / B = " << a / b << std::endl;
	std::cout << "A / B = " << a_f / b_f << "f" << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "\n----------------\nAritmethic tests\n----------------\n";
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl << std::endl;
	std::cout << "A < B => " << (a < b) << std::endl;
	std::cout << "A > B => " << (a > b) << std::endl;
	a = b;
	Fixed c = 5.4556f;
	std::cout << std::endl << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl << std::endl;
	std::cout << "A <= B => " << (a <= b) << std::endl;
	std::cout << "A <= C => " << (a <= c) << std::endl << std::endl;
	std::cout << "A >= B => " << (a >= b) << std::endl;
	std::cout << "A >= C => " << (a >= c) << std::endl << std::endl;
	std::cout << "A == B => " << (a == b) << std::endl;
	std::cout << "A == C => " << (a == c) << std::endl << std::endl;
	std::cout << "A != B => " << (a != b) << std::endl;
	std::cout << "A != C => " << (a != c) << std::endl << std::endl;
	return 0;
}
