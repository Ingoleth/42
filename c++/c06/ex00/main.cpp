#include <string>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <float.h>
#include <string>

void is_float(std::string nb_str)
{
	float nb;

	nb = atof(nb_str.c_str());

	std::cout << "Conversion type = float\n";
	if (nb_str[0] >= '0' && nb_str[0] <= '9' )
	{
		std::cout << "Char: ";
		if (nb >= 32 && nb <= 126)
			std::cout << '\'' << static_cast <char> (nb) << '\'' << std::endl;
		else
			std::cout << "Non displayable\n";
		if (nb > static_cast <double> (INT_MAX) || nb < static_cast <double> (INT_MIN))
			std::cout << "int: impossible\n";
		else
		std::cout << "Int: " << static_cast <int> (nb) << std::endl;
	}
	else
	{
		std::cout << "Char: Impossible\n";
		std::cout << "Int: Impossible\n";
	}
	if (nb - static_cast <int> (nb))
	{
		std::cout << "Float: " << nb <<"f" << std::endl;
		std::cout << "Double: " << static_cast <double> (nb)  << std::endl;
	}
	else
	{
		std::cout << "Float: " << static_cast <float> (nb) <<".0f" << std::endl;
		std::cout << "Double: " << nb <<".0" << std::endl;
	}
}


void is_double(std::string nb_str)
{
	double nb;

	nb = atof(nb_str.c_str());

	std::cout << "Conversion type = double\n";
	if (nb_str[0] >= '0' && nb_str[0] <= '9')
	{
		std::cout << "Char: ";
		if (nb >= 32 && nb <= 126)
			std::cout << '\'' << static_cast <char> (nb) << '\'' << std::endl;
		else
			std::cout << "Non displayable\n";
		if (nb > static_cast <double> (INT_MAX) || nb < static_cast <double> (INT_MIN))
			std::cout << "int: impossible\n";
		else
		std::cout << "Int: " << static_cast <int> (nb) << std::endl;
	}
	else
	{
		std::cout << "Char: Impossible\n";
		std::cout << "Int: Impossible\n";
	}
	if (nb - static_cast <int> (nb))
	{
		std::cout << "Float: " << static_cast <float> (nb) <<"f" << std::endl;
		std::cout << "Double: " << nb << std::endl;
	}
	else
	{
		std::cout << "Float: " << static_cast <float> (nb) <<".0f" << std::endl;
		std::cout << "Double: " << nb <<".0" << std::endl;
	}
}

void is_integer(int i)
{
	std::cout << "Conversion type = int\n";
	if (i >= 32 && i <= 126)
		std::cout << "Char: " << '\'' << static_cast <char> (i) << '\'' << std::endl;
	else
		std::cout << "Char: " << "Non displayable\n";
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << static_cast <float> (i) <<".0f" << std::endl;
	std::cout << "Double: " << static_cast <double> (i) <<".0" << std::endl;
}

void is_char(char c)
{
	std::cout << "Conversion type = char\n";
	std::cout << "Char: " << '\'' << c << '\'' << std::endl;
	std::cout << "Int: " << static_cast <int> (c) << std::endl;
	std::cout << "Float: " << static_cast <float> (c) <<".0f" << std::endl;
	std::cout << "Double: " << static_cast <double> (c) <<".0" << std::endl;
}


int main (int argc, char **argv)
{
	int i;
	std::string aux;

	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	i = 0;
	aux = argv[1];
	if ((aux >= "0" && aux <= "9" && aux.length() == 1) ||
		(aux.find('.') == aux.find('f')))
		is_integer(atoi(argv[1]));
	else if (argv[1][0] >= 32 && argv[1][0] <= 126 && !argv[1][1])
		is_char(argv[1][0]);
	else if (!(aux.find('.') == aux.find('f')))
		is_float(argv[1]);
	else
		is_double(argv[1]);
}