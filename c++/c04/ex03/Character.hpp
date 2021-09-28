#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
#include "Icharacter.hpp"

class Character : public virtual ICharacter
{

	public:

		Character();
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );

	private:
		AMateria *inventory[4];
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */