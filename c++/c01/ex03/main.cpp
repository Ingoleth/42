#include <iostream>
#include "weapon.hpp"
#include "humanA.hpp"
#include "humanB.hpp"

int main(void)
{
	{
		weapon club = weapon("crude spiked club");

		humanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
			weapon club = weapon("crude spiked club");

		humanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(nullptr);
		jim.attack();
	}
	return 0;
}
