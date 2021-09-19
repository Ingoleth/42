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
/*
**	OPERATORS
*/
	const Fixed &operator = (const Fixed &obj);
	Fixed operator ++ ();
	Fixed operator -- ();
	Fixed operator ++ (int);
	Fixed operator -- (int);

	float operator * (const Fixed &obj);
	float operator / (const Fixed &obj);
	float operator - (const Fixed &obj);
	float operator + (const Fixed &obj);
	
	bool operator > (const Fixed &obj);
	bool operator < (const Fixed &obj);
	bool operator >= (const Fixed &obj);
	bool operator <= (const Fixed &obj);
	bool operator == (const Fixed &obj);
	bool operator != (const Fixed &obj);
/*
**	GETTERS & SETTERS
*/
	int getRawBits() const;
	void setRawBits(int value);
/*
**	TRANSFORMATIONS
*/
	int toInt() const; 
	float toFloat() const;
/*
**	UTILITIES
*/
	void displayBits() const;
	static Fixed &max(Fixed &n1, Fixed &n2);
	static Fixed &min(Fixed &n1, Fixed &n2);
	static const Fixed &max(const Fixed &n1, const Fixed &n2);
	static const Fixed &min(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& nb);

#endif