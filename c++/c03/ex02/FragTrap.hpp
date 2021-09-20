#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:

		FragTrap(const std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();

		void highFivesGuys();

private:
	/* data */

};



#endif /* ******************************************************** CLAPTRAP_H */