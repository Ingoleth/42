#include "classZombie.hpp"
#include <iostream>

classZombie::classZombie() : name ("unnamed") {}

classZombie::classZombie(std::string name)
{
	this->name = name;
}

classZombie::~classZombie()
{
	if (name.length())
		std::cout << name << " died..." << std::endl;	
}

void	classZombie::setName(std::string name)
{
	this->name = name;
}

void	classZombie::announce(void)
{
	std::cout << "<" << name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}