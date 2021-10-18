#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	type = "Undefined";
	std::cout << "An undefined (wrong) animal has been created!\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	type = src.type;
	std::cout << "An undefined (wrong) animal has been copied!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "An undefined (wrong) animal has been destroyed!\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->type = rhs.type;
	std::cout << "An undefined (wrong) animal has been copied!\n";
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "Type =" << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	WrongAnimal::getType( void ) const
{
	return type;
}

void		WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal goes Moooooo...\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */