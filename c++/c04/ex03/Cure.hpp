#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public virtual AMateria
{

	public:

		Cure();
		~Cure();
		
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif /* ************************************************************ CURE_H */