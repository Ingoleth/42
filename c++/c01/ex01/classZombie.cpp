#include "classZombie.hpp"
#include <iostream>

classZombie::classZombie() //Can I not have you?
{

}

classZombie::classZombie(std::string name)
{
	this->name = name;
}

classZombie::~classZombie()
{
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