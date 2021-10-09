#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; knownMateria[i]; i++)
		delete knownMateria[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (size_t i = 0; i < 4; i++)
	{
		knownMateria[i] = rhs.knownMateria[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria*materiaToLearn)
{
	int i = 0;

	while (knownMateria[i])
		i++;
	if (i == 4)
		return ;
	knownMateria[i] = materiaToLearn;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (knownMateria[i])
	{
		if (knownMateria[i]->getType() == type)
			return (knownMateria[i]->clone());
		i++;
	}
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */