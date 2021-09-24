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
		DiamondTrap(const std::string name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();	


private:
	/* data */

};



#endif /* ******************************************************** CLAPTRAP_H */