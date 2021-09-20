#include "FragTrap.hpp"

int main()
{
	FragTrap a("Tom");
	FragTrap b(a);

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
	a.highFivesGuys();
	b.highFivesGuys();
	return 0;
}
