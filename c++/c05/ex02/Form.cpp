#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _target("unnamed"), _gradeToExecute(150), _gradeToSign(150)
{

}

Form::Form(const std::string &name, const std::string &target, const int &execGrade, const int &signGrade): _name(name), _target(target), _isSigned(false), _gradeToExecute(execGrade), _gradeToSign(signGrade)
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
	o << "Form " << i.getName() << " (Signed = " << i.getIsSigned() << "; Grade to sign: " << i.getGradeToSign() << "; Grade to execute = " << i.getGradeToExecute() << ")\n";
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

void Form::execute(Bureaucrat const & executor) const throw(Form::GradeTooLowException, Form::NotSignedException)
{
	if (!_isSigned)
		throw(NotSignedException());
	if (executor.getGrade() > _gradeToExecute)
		throw(GradeTooLowException());
	executeForm();
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

const std::string&	Form::getTarget( void ) const
{
	return (_target);
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

const char	*Form::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

/* ************************************************************************** */