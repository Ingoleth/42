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
		Form( Form const & src );
		Form(const std::string &name, const int &signGrade, const int &execGrade);
		~Form();

		Form &		operator=( Form const & rhs );
		int getGradeToSign() const;
		int getGradeToExecute() const;
		int getIsSigned() const;
		const std::string &getName() const;
		void beSigned(const Bureaucrat &signer) throw (Form::GradeTooLowException, Form::SignedException);
	
	private:
		bool				_isSigned;
		std::string const	_name;
		int					_gradeToExecute;
		int					_gradeToSign;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */