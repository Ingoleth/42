#include "Fixed.hpp"
#include <iostream>

void Fixed::operator = (const Fixed &obj)
{
	std::cout << "Assignation operator called\n";
	this->value = obj.getRawBits();
}

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	this->value = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (value);
}

void Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called\n";
	this->value = value;
}