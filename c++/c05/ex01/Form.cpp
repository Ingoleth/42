#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _isSigned(false), _name("Unnamed"), _gradeToExecute(150), _gradeToSign(150) {}

Form::Form( const Form & src ) : _isSigned(src._isSigned), _name(src._name), _gradeToExecute(src._gradeToExecute), _gradeToSign(src._gradeToSign) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const &) // Can't really do you, can I?;
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form " << i.getName() << " (Signed = " << i.getIsSigned() << "; Grade to sign: " << i.getGradeToSign() << "; Grade to execute = " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::sign(const Bureaucrat &signer) throw (Form::GradeTooHighException, Form::GradeTooLowException)
{
	try
	{
		if (signer.getGrade() < _gradeToSign)
			throw (GradeTooLowException());
		_isSigned = true;
	}
	catch(const std::exception& e)
	{
		std::cout << signer.getName() << " cannot sign because "; 
		std::cerr << e.what() << '\n';
	}
}	

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToSign);
}

int Form::getIsSigned() const
{
	return (_gradeToSign);
}

const std::string &Form::getName() const
{
	return (_name);
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

/* ************************************************************************** */