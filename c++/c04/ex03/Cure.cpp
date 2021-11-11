#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure") {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

	AMateria* Cure::clone() const { return new Cure(); }

	void Cure::use(ICharacter& target)
	{
		std::cout << "heals " << target.getName() << " wounds";
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */