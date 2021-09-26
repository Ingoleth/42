#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	type = "Undefined";
	std::cout << "An undefined animal has been created!\n";
}

Animal::Animal( const Animal & src )
{
	type = src.type;
	std::cout << "An undefined animal has been copied!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "An undefined animal has been destroyed!\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Type =" << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Animal::getType( void ) const
{
	return type;
}

void		Animal::makeSound() const
{
	std::cout << "An abstract entity such as an undefined animal may not produce a specific sound...\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */