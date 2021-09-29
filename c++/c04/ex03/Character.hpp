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
		Character( std::string name );
		~Character();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character &		operator=( Character const & rhs );

	private:
		AMateria *inventory[4];
		const std::string _name;
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */