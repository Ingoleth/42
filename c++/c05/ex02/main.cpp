#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void tryForm(const Bureaucrat &user, const Bureaucrat &user2, Form *formToUse)
{
	std::cout << "-----\n";
	std::cout << '\n' << *formToUse << '\n' << std::endl;
	user.signForm(*formToUse);
	std::cout << '\n';
	user2.executeForm(*formToUse);
	std::cout << "-----\n";
}

void tryForm(const Bureaucrat &user, Form *formToUse)
{
	std::cout << "-----\n";
	std::cout << *formToUse;
	user.signForm(*formToUse);
	user.executeForm(*formToUse);
	std::cout << "-----\n";
}

int main( void )
{
	Bureaucrat Bob("Bob", 1);
	Bureaucrat Martin("Martin", 150);

	RobotomyRequestForm A("Fred");
	std::cout << "Grade to sign a robotomy request: 72;\nGrade to execute it: 45\n\n";
	tryForm(Martin, &A);
	tryForm(Bob, &A);
	
	ShrubberyCreationForm B("Fred");
	std::cout << "Grade to sign a shrubbery creation form: 145;\nGrade to execute it: 137\n\n";
	tryForm(Martin, &B);
	tryForm(Bob, &B);
	std::cout << "Grade to sign a presidential pardon request: 25;\nGrade to execute it: 5\n\n";
	PresidentialPardonForm C("Fred");
	tryForm(Martin, &C);
	tryForm(Bob, &C);
	return 0;
}
