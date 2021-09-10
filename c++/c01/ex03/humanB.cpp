#include <iostream>
#include "humanB.hpp"

humanB::humanB(std::string name)
{ 	
	this->name = name;
	weapon = nullptr;
}

humanB::~humanB()
{
}

void	humanB::setWeapon(class weapon &weapon)
{
	this->weapon = &weapon;
}

void	humanB::attack(void)
{
	if (weapon == nullptr)
		std::cout << name << " attacks with his bare fists" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}