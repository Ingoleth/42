#include "classZombie.hpp"
#include <iostream>

int	getnames(int N, std::string name, std::string *ptr)
{
	int pos;
	int prev_pos;
	int i;


	if (name.size() == 0 || N == 0)
		return (0);
	i = pos = prev_pos = 0;
	do
	{
		i++;
		prev_pos = pos;
		pos = name.find(',', pos + 1);

		if (pos == prev_pos + 1)
			i--;
		else
			ptr[i - 1] = name.substr(prev_pos + 1, pos - prev_pos - 1);
	}	while (pos != -1);
	if (prev_pos == (int)name.size() - 1)
		i--;
	return (i);
}


Zombie *zombieHorde(int N, std::string name)
{
	Zombie		*ptr;
	int			i;
	std::string	name_list[N];

	i = getnames(N, name, name_list);
	return (nullptr);
	ptr = new Zombie[N - 1];
	i = 0;
	
	return (0);
}