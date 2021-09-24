#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap \"" << name << "\" created!\n";
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap \"" << name << "\" created!\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ) : ClapTrap(src.name + "_clap_name")
{
	name = src.name;
	ClapTrap::name = src.ClapTrap::name;
	energyPoints = src.energyPoints;
	hitPoints = hitPoints;
	attackDamage = attackDamage;

	std::cout << "DiamondTrap \"" << name << "\" duplicated!\n";
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

void DiamondTrap::whoAmI()
{
	std::cout << name << std::endl;
	std::cout << ClapTrap::name << std::endl;	
}