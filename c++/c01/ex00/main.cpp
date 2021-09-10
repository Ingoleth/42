#include "classZombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie *ptr;

	ptr = newZombie("Evans");
	ptr->announce();
	randomChump("Criss");
	delete ptr;
}

Zombie* newZombie( std::string name )
{
	Zombie* ptr;

	ptr = new Zombie(name);
	return(ptr);
}

void randomChump( std::string name )
{
	Zombie aux(name);

	aux.announce();
}