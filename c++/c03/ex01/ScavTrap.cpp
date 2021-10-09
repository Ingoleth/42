#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap \"" << name << "\" created (via default constructor)!\n";
}

ScavTrap::ScavTrap(const std::string name)
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
** -------------------------------- OVERLOAD --------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	return (*this);
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