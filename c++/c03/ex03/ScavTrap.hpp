#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );
		void guardGate();

private:
	/* data */

};



#endif /* ******************************************************** CLAPTRAP_H */