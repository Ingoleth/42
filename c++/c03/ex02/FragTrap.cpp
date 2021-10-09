#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap \"" << name << "\" created (via default constructor)!\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
		this->name = name;
		hitPoints = 100;
		energyPoints = 100;
		attackDamage = 30;
	std::cout << "FragTrap \"" << name << "\" created!\n";
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << "FragTrap \"" << name << "\" created!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap \"" << name << "\" destroyed!\n";
}

/*
** -------------------------------- OVERLOAD --------------------------------
*/

FragTrap &FragTrap::operator=( FragTrap const & rhs )
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys()
{
		std::cout << name << " high fives\n";
}