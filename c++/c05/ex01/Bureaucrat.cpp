#include "Bureaucrat.hpp"
#include <exception>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150){}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs._grade;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << "<" << i.getName() << ">, bureaucrat grade <" << i.getGrade() << ">";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
		void Bureaucrat::incrementGrade( void ) throw(GradeTooHighException)
		{
			if (_grade == 1)
				throw (GradeTooHighException());
			_grade--;
		}

		void Bureaucrat::decrementGrade( void ) throw(GradeTooLowException)
		{
			if (_grade == 150)
				throw (GradeTooLowException());
			_grade++;
		}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

/* ************************************************************************** */



/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade can't be smaller than 1!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade can't be bigger than 150");
}
