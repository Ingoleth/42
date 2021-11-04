#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat Bob("Bob", 100);
	Form A("A", 99, 98);

	std::cout << A << std::endl;
	std::cout << Bob << std::endl;
	Bob.sign(A);
	Bob.incrementGrade();
	Bob.sign(A);
	return 0;
}
