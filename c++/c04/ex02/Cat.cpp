#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "A Cat has been created!\n";
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	std::cout << "A Cat has been created!\n";
	brain = new Brain();
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed!\n";
	delete brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "A Cat has been copied!\n";
	this->type = rhs.getType();
	*brain = *rhs.brain;
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

void		Cat::think( std::string thought )
{
	brain->setIdea(thought);
}

void		Cat::thinkOutloud( void )
{
	std::cout << *brain;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */