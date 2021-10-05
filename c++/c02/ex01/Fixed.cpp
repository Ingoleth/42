#include "Fixed.hpp"
#include <iostream>

// OPERATORS

void Fixed::operator = (const Fixed &obj)
{
	std::cout << "Assignation operator called\n";
	this->value = obj.value;
}

std::ostream& operator<<(std::ostream& os, const Fixed& nb)
{
	os << nb.toFloat();
	return (os);
}

// CONSTRUCTORS

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->value = value << fractionalBits;
	if (((value >> 31) & 0))
		this->value |= 1UL << 31;
}

Fixed::Fixed(const float value)
{
	int aux;
	float auxFloat;

	std::cout << "Float constructor called\n";
	aux = (int) value;
	this->value = aux << fractionalBits;
	if (((aux >> 31) & 0))
		this->value |= 1UL << 31;
	auxFloat = value - aux;
	if (auxFloat < 0)
		auxFloat *= -1;
	{
		float decimalValue = 0.5;
		for (int i = 7; i >= 0; i--, decimalValue /= 2)
		{
			if (auxFloat - decimalValue >= 0 )
			{
				this->value |= 1UL << i;
				auxFloat -= decimalValue;
			}
			else if (decimalValue - auxFloat < auxFloat - getMaxRepresentation(i - 1, decimalValue / 2))
			{
				this->value |= 1UL << i;
				break ;	
			}
		}
	}
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// SETTERS & GETTERS

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

// Conversions

int Fixed::toInt() const
{
	return (value >> fractionalBits);
}

float Fixed::toFloat() const 
{
	float nb;
	float decNb = 0;
	int aux = 2;

	for (int i = fractionalBits - 1; i >= 0; i--, aux *= 2)
	{
		if ((value >> i) & 1)
			decNb += 1.0f / aux;
	}
	nb = this->toInt();
	if (nb >= 0)
		nb += decNb;
	else
		nb -= decNb;
	return(nb);
}

// UTILS

void Fixed::displayBits() const
{
	int count = 0;
	for (int i = 31; i >= 0; i--)
	{
		if ((value >> i) & 1)
			std::cout << 1;
		else
			std::cout << 0;
		if(++count == 4) {std::cout << " "; count = 0;}
	}
	std::cout << std::endl;
}

float Fixed::getMaxRepresentation(int bitIndex, float decimalValue) const
{
	float nb;

	nb = 0;
	for (int i = bitIndex; i >= 0; i--, decimalValue /= 2)
		nb += decimalValue;
	return (nb);
}
