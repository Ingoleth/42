#include "Bureaucrat.hpp"

int main( void )
{
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat bart("Bart", 150);
		
		try
		{
			std::cout << bob << "\nTrying to increment Bob's grade...\n";
			bob.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << bart << "\nTrying to decrement Bart's grade...\n";
			bart.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try
	{
		std::cout<< "\nTrying to create a bureaucrat with grade 0...\n";
		Bureaucrat bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<< "\nTrying to create a bureaucrat with grade 151...\n";
		Bureaucrat bob("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
