#include "tests.hpp"

void print_header(std::string str, bool green)
{
	int margin = (MARGIN - str.length()) / 2;
	std::cout << (green ? GREEN : BLUE);
	if (green)
		std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::string(margin, '-') << ' ' << str << ' ' << std::string(margin, '-') << std::endl;
	std::cout << std::endl;
	std::cout << RESET;
};