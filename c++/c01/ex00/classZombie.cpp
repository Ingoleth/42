#include "classZombie.hpp"
#include <iostream>

classZombie::classZombie(std::string name)
{
	this->name = name;
}

classZombie::~classZombie()
{
	std::cout << name << " died..." << std::endl;	
}

void	classZombie::announce(void)
{
	std::cout << "<" << name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}