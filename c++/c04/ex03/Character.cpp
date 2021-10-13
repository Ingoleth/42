#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("Unnamed")
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character( const Character & src ) : _name(src.getName()) { *this = src; }

Character::Character ( const std::string name ) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
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

/*
** --------------------------------- METHODS ----------------------------------
*/

	void Character::equip(AMateria* m)
	{
		int i = 0;

		while (inventory[i])
		{
			if (inventory[i] == m)
				return ;
			i++;
		}
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
		std::cout << "* ";
		inventory[idx]->use(target);
		std::cout << " *\n";
	}

	const std::string &Character::getName() const
	{
		return ( _name );
	}

	AMateria *Character::getInventorySlot(int i) const
	{
		return (inventory[i]);
	}

	void Character::display_info( void ) const
	{

	std::cout << "Name = " << this->_name << "\nInventory:\n";
	for (size_t j = 0; j < 4; j++)
	{
		std::cout << j << ".- ";
		if (inventory[j] != nullptr)
			std::cout << inventory[j]->getType() << "\n";
		else
			std::cout << "empty\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */