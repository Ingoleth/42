#ifndef CLASS_ZOMBIE
# define CLASS_ZOMBIE

#include <string>

typedef class classZombie
{

private:

	std::string name;

public:

	classZombie(std::string name);
	~classZombie();
	
	void	announce(void);
} Zombie;

#endif