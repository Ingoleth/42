#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Tom");
	ClapTrap b(a);

	std::cout << a;
	b.setName("Fred");
	b.setAttackDamage(15);
	std::cout << b;
	b = a;
	std::cout << b;
	a.attack("Pete");
	a.takeDamage(5);
	a.beRepaired(10);
	b.setName("Fred");
	return 0;
}
