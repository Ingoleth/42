#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class weapon
{
private:
	std::string type;
public:
	weapon(void);
	weapon(std::string type);
	~weapon();
	void	setType(std::string type);
	std::string	getType(void) const;
};

#endif // WEAPON_H
