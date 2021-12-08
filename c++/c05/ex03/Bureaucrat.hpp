#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
class Form;
# include "Form.hpp"

class GradeTooLowException;
class GradeTooHighException;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		int getGrade() const;
		const std::string &getName( void ) const;
		void incrementGrade( void ) throw(GradeTooHighException);
		void decrementGrade( void ) throw(GradeTooLowException);
		void signForm(Form &Form) const;
		void executeForm(Form const & form) const;

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

		Bureaucrat &		operator=( Bureaucrat const & rhs );

	protected:
		const std::string	_name;
		int					_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */