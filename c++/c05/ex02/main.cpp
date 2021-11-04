#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void tryForm(const Bureaucrat &user, const Bureaucrat &user2, Form *formToUse)
{
	std::cout << *formToUse << std::endl;
	user.sign(*formToUse);
	user2.executeForm(*formToUse);
}

void tryForm(const Bureaucrat &user, Form *formToUse)
{
	std::cout << *formToUse;
	user.sign(*formToUse);
	user.executeForm(*formToUse);
}

int main( void )
{
	Bureaucrat Bob("Bob", 1);
	Bureaucrat Martin("Martin", 150);

	RobotomyRequestForm A("Fred");
	std::cout << "Grade to sign a robotomy request: 72; Grade to execute it: 45\n";
	tryForm(Martin, &A);
	tryForm(Bob, &A);
	tryForm(Bob, Martin, &A);
	std::cout << "Grade to sign a shrubbery creation form: 145; Grade to execute it: 137";

	std::cout << "Grade to sign a presidential pardon request: 25; Grade to execute it: 5\n";
	PresidentialPardonForm C("Fred");
	tryForm(Martin, &C);
	tryForm(Bob, &C);
	tryForm(Bob, Martin, &C);
	return 0;
}
