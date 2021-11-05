#include <iostream>

int main (int argc, char **argv)
{
	char *aux;
	float input;

	aux = nullptr;
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	try
	{
		input = std::strtof(argv[1], &aux);
		if (!aux)
			std::cout << input << std::endl;
		else
			std::cout << "Error, hopefully?\n";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}