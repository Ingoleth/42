#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
		this->name = name;
		hitPoints = 100;
		energyPoints = 50;
		attackDamage = 20;
	std::cout << "ScavTrap \"" << name << "\" created!\n";
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap \"" << name << "\" created!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \"" << name << "\" destroyed!\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate()
{
		std::cout << "ScavTrap " << name << " is on guard mode\n";
}