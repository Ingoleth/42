#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public virtual AMateria
{

	public:

		Ice();
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif /* ************************************************************* ICE_H */