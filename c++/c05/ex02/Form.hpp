#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Bureaucrat;
# include "Bureaucrat.hpp"

class Form
{

	public:

		class SignedException : public std::exception
		{  
			public:  
				const char * what() const throw();
		};

		class NotSignedException : public std::exception
		{  
			public:  
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{  
			public:  
				const char * what() const throw();
		};
		class GradeTooHighException : public std::exception
		{  
			public:  
				const char * what() const throw();
		};
		Form();
		Form(const std::string &name, const std::string &target, const int &execGrade, const int &signGrade);
		virtual ~Form();

		Form &		operator=( Form const & rhs );
		int getGradeToSign() const;
		int getGradeToExecute() const;
		int getIsSigned() const;
		const std::string &getName() const;
		const std::string&	getTarget( void ) const;
		void beSigned(const Bureaucrat &signer) throw (Form::GradeTooLowException, Form::SignedException);
		void execute(Bureaucrat const & executor) const throw(Form::GradeTooLowException, Form::NotSignedException);
		virtual void executeForm() const = 0;
	
	private:
		const std::string		_name;
		const std::string		_target;
		bool					_isSigned;
		const int				_gradeToExecute;
		const int				_gradeToSign;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */