#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();
		int getGrade() const;
		const std::string &getName( void ) const;
		void incrementGrade( void );
		void decrementGrade( void );

		Bureaucrat &		operator=( Bureaucrat const & rhs );

	protected:
		const std::string name;
		int grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */