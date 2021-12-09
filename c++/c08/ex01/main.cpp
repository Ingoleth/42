#include <iostream>
#include <algorithm>
#include <exception>
#include "Span.hpp"

int main( void )
{
	Span	span(6);
	span.addNumber(5);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);
	span.printDebugInfo();
	std::cout << "Span span\n";
	std::cout << "Shortest span: " << span.shortestSpan() << '\n';
	std::cout << "Longest span: " << span.longestSpan() << '\n';



	std::cout << "\n\nCopy span = span\n\n";
	Span	copy_span = span;
	std::cout << "A 20 is added to copy spawn\n";
	copy_span.addNumber(20);
	copy_span.printDebugInfo();
	std::cout << "\nCopy span\n";
	std::cout << "Shortest span: " << copy_span.shortestSpan() << '\n';
	std::cout << "Longest span: " << copy_span.longestSpan() << '\n';

	std::cout << "\nSpan doesn't change in the original:\n";
	std::cout << "Shortest span: " << span.shortestSpan() << '\n';
	std::cout << "Longest span: " << span.longestSpan() << '\n';



	std::cout << "\nBetter add number\n";
	Span	random_span(100000);
	random_span.fillWithRandNums();
	std::cout << "Shortest span: " << random_span.shortestSpan() << '\n';
	std::cout << "Longest span: " << random_span.longestSpan() << '\n';


	std::cout << "\n\nException test\n";
	try
	{
		Span except_span(std::vector<int>().max_size() + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span	except_span(1);
	except_span.addNumber(5);
	try
	{
		except_span.addNumber(200);
		std::cout << "Second number added to the 1 length span\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	try
	{
		const int temp = except_span.shortestSpan();
		std::cout << "Shortest span " << temp << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception " << e.what() << '\n';
	}

	return 0;
}