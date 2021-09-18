#ifndef FIXED
# define FIXED

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractionalBits = 8;
	float getMaxRepresentation(int bit, float decimalValue) const;

public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	void displayBits() const;
	int getRawBits() const;
	void setRawBits(int value);
	void operator = (const Fixed &obj);
	int toInt() const; 
	float toFloat() const; 
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif