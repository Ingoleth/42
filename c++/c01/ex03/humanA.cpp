#include <iostream>
#include "humanA.hpp"

humanA::humanA(std::string name, class weapon &wep) : weapon(wep)
{ 	
	this->name = name;
}

humanA::~humanA()
{
}

void	humanA::setWeapon(std::string weapon)
{
	this->weapon.setType(weapon);
}

void	humanA::attack(void)
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}