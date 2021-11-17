#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class Span
{

	public:

		Span();
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

	private:
		size_t _size;
		size_t _shortestSpan;
		size_t _longestSpan;
};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */