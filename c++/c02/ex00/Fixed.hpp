#ifndef FIXED
# define FIXED
class Fixed
{
private:
	int value;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int value);
	void operator = (const Fixed &obj);
};

#endif