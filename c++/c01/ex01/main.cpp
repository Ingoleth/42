#include "classZombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde;
	int i = 0;
	int N = 2;

	horde = zombieHorde(N, "Pete Frank");
	if (horde)
	{
		while (i < N)
		{
			horde[i].announce();
			i++;
		}
		delete[] horde;
	}
	return 0;
}