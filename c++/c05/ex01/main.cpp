#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat Bob("Bob", 100);
	Form A("A", 99, 98);
	

	try
	{
		Form B("Form A", -1, 98);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form B("Form A", 100, 198);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << A << std::endl;
	std::cout << Bob << std::endl;
	Bob.sign(A);
	Bob.incrementGrade();
	Bob.sign(A);
	return 0;
}
