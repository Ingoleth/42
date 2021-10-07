#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include <iostream>
# include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:

		DiamondTrap();
		DiamondTrap( const std::string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		void whoAmI( void );

		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::attackDamage;
		using ScavTrap::attack;



private:
	std::string name;

};



#endif /* ******************************************************** CLAPTRAP_H */