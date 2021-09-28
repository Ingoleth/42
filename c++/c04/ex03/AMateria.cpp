#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : type("undefined") {}

AMateria::AMateria( const AMateria & src ) : type(src.type) {}

AMateria::AMateria( std::string const & type ) : type(type) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AMateria::use(ICharacter& target)
{
	(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	std::string const & AMateria::getType() const { return type; }

/* ************************************************************************** */