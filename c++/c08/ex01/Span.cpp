#include "Span.hpp"
# include <algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(  ) : _max_size(0), _elements(0), _sorted(false){}

Span::Span( const Span & src )
{
	*this = src;
}

Span::Span( size_t size ) : _max_size(size), _elements(0), _sorted(false){}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	this->_elements = rhs._elements;
	this->_max_size = rhs._max_size;
	this->_sorted = rhs._sorted;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int nb) throw (std::range_error)
{
	if (_elements.size() == _max_size)
		throw (std::range_error("Can't add more numbers!"));
	if (_elements.size() && _elements.back() > nb)
		_sorted = false;
	_elements.push_back(nb);
}

int Span::longestSpan( void ) const
{
	if (_elements.size() <= 1)
		throw std::length_error("Two numbers are required for a span calculation");
	if (_sorted)
		return (_elements.back() - _elements.front());
	std::vector<int>::const_iterator min_elem = std::min_element(_elements.begin(), _elements.end());
	std::vector<int>::const_iterator max_elem = std::max_element(_elements.begin(), _elements.end());
	return (*max_elem - *min_elem);
} 	

int Span::shortestSpan( void )
{
	if (_elements.size() <= 1)
		throw std::length_error("Two numbers are required for a span calculation");
	if (!_sorted)
	{
		std::sort(_elements.begin(), _elements.end());
		_sorted = true;
	}
	std::vector<int>::const_iterator it = _elements.begin();
	int	span = abs(it[0] - it[1]);
	while (++it + 1 < _elements.end())
	{
		const int new_span = abs(it[0] - it[1]);
		if (new_span < span)
			span = new_span;
	}
	return (span);
	return (span);
		
		return (0);
}

void Span::fillWithRandNums()
{
	srand(time(NULL));
	_elements = std::vector <int> (_max_size);
	for (std::vector<int>::iterator i = _elements.begin(); i != _elements.end(); ++i)
		*i = rand() % 10000;
}

void Span::printDebugInfo( void )
{
	std::cout << "--------------\nVector content\n--------------\n";
	for (std::vector<int>::iterator i = _elements.begin(); i != _elements.end(); ++i)
	{
		std::cout << *i << "\n";
	}
	std::cout << "--------------\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */