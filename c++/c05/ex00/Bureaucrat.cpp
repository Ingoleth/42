#include "Bureaucrat.hpp"
#include <exception>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
		int Bureaucrat::getGrade() const
		{
			return (grade);
		}

		const std::string &Bureaucrat::getName() const
		{
			return (name);
		}

		void incrementGrade( void )
		{
			if (grade == 1)
				throw (1);
			grade--;
		}

		void decrementGrade( void )
		{

		}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */



class GradeTooLowException : public exception
{  
    public:  
        const char * what() const throw()  
        {  
            return "Grade is already the lowest!\n";  
        }  
};

class GradeTooHighException : public exception
{  
    public:  
        const char * what() const throw()  
        {  
            return "Grade is already the higest!\n";  
        }  
};