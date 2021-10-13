#include "MateriaSource.hpp"
#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		knownMateria[i] = nullptr;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (knownMateria[i])
			delete knownMateria[i];
	}
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (size_t i = 0; i < 4; i++)
		knownMateria[i] = rhs.knownMateria[i]->clone();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *materiaToLearn)
{
	int i = 0;

	while (knownMateria[i])
	{
		if (knownMateria[i] == materiaToLearn)
			return ;
		i++;
	}
	if (i == 4)
		return ;// delete the thing?
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

void	MateriaSource::displayKnownMateria( void ) const
{
	for (size_t j = 0; j < 4; j++)
	{
		std::cout << j << ".- ";
		if (knownMateria[j] != nullptr)
			std::cout << knownMateria[j]->getType() << "\n";
		else
			std::cout << "empty\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */