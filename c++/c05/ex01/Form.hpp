#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();

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


		Form &		operator=( Form const & rhs );
		int getGradeToSign() const;
		int getGradeToExecute() const;
		int getIsSigned() const;
		const std::string &getName() const;
		void sign(const Bureaucrat &signer) throw (Form::GradeTooHighException, Form::GradeTooLowException);
	
	private:
		bool				_isSigned;
		std::string const	_name;
		int const			_gradeToExecute;
		int const			_gradeToSign;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */