#include "FragTrap.hpp"

int main()
{
	FragTrap a("Tom");
	FragTrap b(a);

	std::cout << a;
	std::cout << "\nB output, to prove it has been properly initialized via copy:\n" << b;
	b.setName("Fred");
	b.setAttackDamage(15);
	std::cout << "\nB output, to prove the changes:\n" << b;
	b = a;
	std::cout << "\nB output, to prove it has been properly copied:\n" << b;
	b.setName("Fred"); //Name is changed again for attack test and destructor
	a.attack("Pete");
	a.takeDamage(5);
	a.beRepaired(10);
	a.highFivesGuys();
	b.highFivesGuys();
	return 0;
}
