#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "A Cat has been created!\n";
	this->type = "Cat";
}

Cat::Cat( const Cat & src )
{
	std::cout << "A Cat has been created!\n";
	this->type = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed!\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "A Cat has been copied!\n";
	this->type = rhs.getType();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType() << std::endl;
	return o;
}
 

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Cat::makeSound() const
{
	std::cout << "Meow Meow!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */