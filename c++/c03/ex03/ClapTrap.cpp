#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
{
		this->name = "Unnamed";
		hitPoints = 10;
		energyPoints = 10;
		attackDamage = 0;
	std::cout << "ClapTrap \"" << name << "\" created!\n";
}

ClapTrap::ClapTrap(const std::string name)
{
		this->name = name;
		hitPoints = 10;
		energyPoints = 10;
		attackDamage = 0;
	std::cout << "ClapTrap \"" << name << "\" created!\n";
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	std::cout << "ClapTrap \"" << name << "\" created!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap \"" << name << "\" destroyed!\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
{
	o << "-----\n";
	o << i.getName() << std::endl;
	o << i.getHitPoints() << std::endl;
	o << i.getEnergyPoints() << std::endl;
	o << i.getAttackDamage() << std::endl;
	o << "-----\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack( std::string const & target )
{
	std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << name << " takes " << amount << " points of damage!\n";
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
}

void ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << name << " is repared by " << amount << " points!\n";
	hitPoints += amount;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	std::string ClapTrap::getName ( void ) const
	{
		return (name);
	}

	int ClapTrap::getHitPoints( void ) const
	{
		return (hitPoints);
	}

	int ClapTrap::getEnergyPoints( void ) const
	{
		return (energyPoints);
	}

	int ClapTrap::getAttackDamage( void ) const
	{
		return (attackDamage);
	}

	void ClapTrap::setName( std::string name )
	{
		this->name = name;
	}

	void ClapTrap::setHitpoints( int hitPoints )
	{
		this->hitPoints = hitPoints;
	}

	void ClapTrap::setEnergyPoints( int energyPoints )
	{
		this->energyPoints = energyPoints;
	}

	void ClapTrap::setAttackDamage( int attackDamage )
	{
		this->attackDamage = attackDamage;
	}

/* ************************************************************************** */