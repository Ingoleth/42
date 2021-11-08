#include <string>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <float.h>
#include <string>

void is_float(std::string nb_str)
{
	float nb;

	nb = atof(nb_str);

	if (nb_str[0] >= '0' && nb_str <= '9')
	{
		if (nb >= 32 && nb <= 126)
			std::cout << 
	}	
}


int main (int argc, char **argv)
{
	int i;
	float input;
	std::string aux;

	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	i = 0;
	aux = argv[1];
	if (aux.find('.') == -1 && aux.find('f') == -1)
		is_integer();
	else
		is_float();
}