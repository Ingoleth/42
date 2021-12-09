#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _isSigned(false), _name("Unnamed"), _gradeToExecute(150), _gradeToSign(150) {}

Form::Form( const Form & src ) : _isSigned(src._isSigned), _name(src._name), _gradeToExecute(src._gradeToExecute), _gradeToSign(src._gradeToSign) {}

Form::Form(const std::string  &name, const int &signGrade, const int &execGrade) : _isSigned(false), _name(name), _gradeToExecute(execGrade), _gradeToSign(signGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (GradeTooLowException());
}

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
	o << "Form " << i.getName() << " (Signed = " << i.getIsSigned() << "; Grade to sign: " << i.getGradeToSign() << "; Grade to execute = " << i.getGradeToExecute() << ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat &signer) throw (Form::GradeTooLowException, Form::SignedException)
{
		if (_isSigned)
			throw (SignedException());
		if (signer.getGrade() > _gradeToSign)
			throw (GradeTooLowException());
		_isSigned = true;
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
	return (_gradeToExecute);
}

int Form::getIsSigned() const
{
	return (_isSigned);
}

const std::string &Form::getName() const
{
	return (_name);
}

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char	*Form::SignedException::what() const throw()
{
	return ("form is already signed");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

/* ************************************************************************** */