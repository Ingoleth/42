#ifndef CLASS_ZOMBIE
# define CLASS_ZOMBIE

#include <string>

typedef class classZombie
{

private:

	std::string name;

public:

	classZombie();
	classZombie(std::string name);
	~classZombie();

	void	setName(std::string name);
	
	void	announce(void);
} Zombie;

#endif