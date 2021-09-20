#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap(const std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		std::string getName( void ) const;
		int getHitPoints( void ) const;
		int getEnergyPoints( void ) const;
		int getAttackDamage( void ) const;
		void setName( std::string name );
		void setHitpoints( int hitPoints );
		void setEnergyPoints( int energyPoints );
		void setAttackDamage( int attackDamage );

		void attack( std::string const & target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */