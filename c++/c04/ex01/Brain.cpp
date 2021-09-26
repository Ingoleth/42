#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain created\n";
}

Brain::Brain( const Brain & src )
{
	int i;

	i = 0;
	while (i < 100)
		this->ideas[i] = src.getIdea(i);
	std::cout << "Brain created from another brain\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destroyed\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	int i;

	i = -1;
	while (++i < 100)
		this->ideas[i] = rhs.getIdea(i);
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & Brain )
{
	int i = 0;
	std::string aux;
	while (true)
	{
		if ((aux = Brain.getIdea(i)) != "")
			std::cout << "[" << i << "] = " << aux << std::endl;
		else
			break ;
		i++;
	}
	
	
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
	std::string Brain::getIdea(int i) const
	{
		if (i < 0 || i > 99)
			return ("");
		return (ideas[i]);
	}

	void Brain::setIdea(std::string str)
	{
		int i;

		i = 0;
		while (true)
		{
			if (this->getIdea(i) == "")
				break ;
			i++;
		}
		if (i >= 100)
			return ;
		ideas[i] = str;
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */