#include "weapon.hpp"

weapon::weapon(void)
{
}

weapon::weapon(std::string type)
{
	this->type = type;
}

weapon::~weapon()
{
}

void	weapon::setType(std::string type)
{
		this->type = type;
}

std::string	weapon::getType(void) const
{
	return (type);
}
