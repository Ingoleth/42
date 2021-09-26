#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "A Dog has been created!\n";
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog( const Dog & src )
{
	std::cout << "A Dog has been created!\n";
	brain = new Brain();
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete brain;
	std::cout << "A Dog has been destroyed!\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "A Dog has been copied!\n";
	this->type = rhs.getType();
	*brain = *rhs.brain;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Dog::makeSound() const
{
	std::cout << "Woof woof!\n";
}

void		Dog::think(std::string thought)
{
	brain->setIdea(thought);
}

void		Dog::thinkOutloud( void )
{
	std::cout << brain;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */