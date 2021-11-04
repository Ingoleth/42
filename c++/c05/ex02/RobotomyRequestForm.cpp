#include "RobotomyRequestForm.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest", "unnamed", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequest", target, 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form("RobotomyRequest", src.getTarget(), 25, 5) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const &)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	void RobotomyRequestForm::executeForm() const
	{
		srand(time(NULL));
		if(!(rand() % 2))
			std::cout << "Bzzt...\n Drrrr...\n" << getTarget() << " has been robotomized successfully\n";
		else
			std::cout << "Failed to robotize " << getTarget();
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */