#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat Bob("Bob", 100);
	Form A("A", 99, 98);

	std::cout << A << std::endl;
	std::cout << Bob << std::endl;
	Bob.signForm(A);
	Bob.incrementGrade();
	Bob.signForm(A);
	Bob.signForm(A);
	return 0;
}
