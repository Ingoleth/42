#ifndef HUMAN_B
#define HUMAN_B

# include <string>
# include "weapon.hpp"

class humanB
{
private:
	std::string name;
	weapon *weapon;

public:
	humanB(std::string name);
	~humanB();
	void	setWeapon(class weapon *weapon);
	void	attack(void);
};

#endif // HUMAN_B
