#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap \"" << name << "\" created!\n";
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
		this->name = name;
	std::cout << "DiamondTrap \"" << name << "\" created!\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap \"" << name << "\" created!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap \"" << name << "\" destroyed!\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/