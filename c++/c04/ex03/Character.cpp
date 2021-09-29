#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("Unnamed") {}

Character::Character( const Character & src ) : _name(src.getName()) { *this = src; }

Character::Character ( const std::string name ) : _name(name) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (size_t i = 0; inventory[i]; i++)
		delete inventory[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	for (size_t i = 0; inventory[i]; i++)
		delete inventory[i];
	for (size_t i = 0; rhs.inventory[i]; i++)
		inventory[i] = rhs.inventory[i]->clone();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void Character::equip(AMateria* m)
	{
		int i = 0;

		while (inventory[i])
			i++;
		if (i > 3)
			return ;
		inventory[i] = m;
	}

	void Character::unequip(int idx)
	{
		if (idx < 0 || idx > 3)
			return ;
		inventory[idx] = NULL;	
	}

	void Character::use(int idx, ICharacter& target)
	{
		if (idx < 0 || idx > 3 || !inventory[idx])
			return ;
		inventory[idx]->use(target);
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */