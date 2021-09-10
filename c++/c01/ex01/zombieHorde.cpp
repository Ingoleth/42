#include "classZombie.hpp"
#include <iostream>

int	getnames(int N, std::string name, std::string *ptr)
{
	int pos;
	int prev_pos;
	int i;

	if (name.size() == 0 || N == 0)
		return (0);
	i = 0;
	pos = -1;
	do
	{
		i++;
		prev_pos = pos;
		pos = name.find(' ', pos + 1);
		if (pos == prev_pos + 1)
			i--;
		else if (pos != -1)
		{
			if (i > N)
				return (N);
			ptr[i - 1] = name.substr(prev_pos + 1, pos - prev_pos - 1);
		}
	}	while (pos != -1);
	if (i > N)
		return (N);
	ptr[i - 1] = name.substr(prev_pos + 1, pos - prev_pos - 1);
	return (i);
}

Zombie *zombieHorde(int N, std::string name)
{
	Zombie		*ptr;
	int			i;
	std::string	name_list[N];
	
	ptr = new Zombie[N];
	
	if (getnames(N, name, name_list) != N)
	{
		std::cout << "Not enough names to create the horde!\n";
		delete[] ptr;
		return (nullptr);
	}
	i = 0;
	while (i < N)
	{
		ptr[i].setName(name_list[i]);
		i++;
	}
	return (ptr);
}