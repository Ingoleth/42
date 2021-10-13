#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"


class MateriaSource : public virtual IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();
		void learnMateria(AMateria *materiaToLearn);
		AMateria* createMateria(std::string const & type);
		void	displayKnownMateria( void ) const;

		MateriaSource &		operator=( MateriaSource const & rhs );

	private:
		AMateria *knownMateria[4];
};

#endif /* *************************************************** MATERIASOURCE_H */