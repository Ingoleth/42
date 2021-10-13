#ifndef ISOURCE_HPP
# define ISOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
	public:

	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
	virtual	void	displayKnownMateria( void ) const = 0;
};

#endif