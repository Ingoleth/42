#include "Fixed.hpp"
#include <iostream>

// OPERATORS

const Fixed &Fixed::operator = (const Fixed &obj)
{
	this->value = obj.getRawBits();
	return (*this);
}

Fixed Fixed::operator ++ (int) // ++Fixed
{
	const Fixed aux = *this;

	this->value += 1;
	return (aux);
}

Fixed Fixed::operator -- (int) // --Fixed
{
	const Fixed aux = *this;

	this->value -= 1;
	return (aux);
}

Fixed Fixed::operator ++ () //Fixed++;
{
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator -- () //Fixed--;
{
	this->value -= 1; //Check if overflow
	return (*this);
}

float Fixed::operator * (const Fixed &obj)
{
	return (this->toFloat() * obj.toFloat());
}

float Fixed::operator / (const Fixed &obj)
{
	return (this->toFloat() / obj.toFloat());
}

float Fixed::operator - (const Fixed &obj)
{
	return (this->toFloat() - obj.toFloat());
}

float Fixed::operator + (const Fixed &obj)
{
	return (this->toFloat() + obj.toFloat());
}
	
bool Fixed::operator > (const Fixed &obj)
{
	if (this->value > obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator < (const Fixed &obj)
{
	if (this->value < obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator >= (const Fixed &obj)
{
	if (this->value >= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator <= (const Fixed &obj)
{
	if (this->value <= obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator == (const Fixed &obj)
{
	if (this->value == obj.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator != (const Fixed &obj)
{
	if (this->value != obj.getRawBits())
		return (true);
	return (false);
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
}

Fixed::Fixed(const Fixed &obj)
{
	this->value = obj.getRawBits();
}

Fixed::Fixed(const int value)
{
	this->value = value << fractionalBits;
	if (((value >> 31) & 0))
		this->value |= 1UL << 31;
}

Fixed::Fixed(const float value)
{
	int aux;
	float auxFloat;

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
}

// SETTERS & GETTERS

int Fixed::getRawBits() const
{
	return (value);
}

void Fixed::setRawBits(int value)
{
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

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed &Fixed::max(Fixed const&n1, const Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}

const Fixed &Fixed::min(Fixed const&n1, const Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}
