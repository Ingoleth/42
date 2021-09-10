#ifndef HUMAN_A
#define HUMAN_A

# include <string>
# include "weapon.hpp"

class humanA
{
private:
	std::string name;
	weapon &weapon;

public:
	humanA(std::string name, class weapon &wep);
	~humanA();
	void	setWeapon(std::string weapon);
	void	attack(void);
};

#endif // HUMAN_A
