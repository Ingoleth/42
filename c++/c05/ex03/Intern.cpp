#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & other )
{
	*this = other;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &		Intern::operator=( Intern const & other )
{
	(void) other;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form*			Intern::makeForm( std::string name, std::string target )
{
	std::string options[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form*(Intern::*functions[3])(std::string) =
	{
		&Intern::makeShrubbery,
		&Intern::makeRobot,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == options[i])
		{
			std::cout << "Intern creates " << name << " form\n";
			return (this->*functions[i])(target);
		}
	}
	std::cout << "Intern doesn't know what form to create\n";
	return (NULL);
}

Form	*Intern::makeShrubbery( std::string target )
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeRobot( std::string target )
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makePresidential( std::string target )
{
	return (new PresidentialPardonForm(target));
}
