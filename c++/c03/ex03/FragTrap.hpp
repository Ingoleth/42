#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();
		
		FragTrap &	operator=( FragTrap const & rhs );
		void highFivesGuys();

private:
	/* data */

};



#endif /* ******************************************************** CLAPTRAP_H */