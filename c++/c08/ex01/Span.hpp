#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span();
		Span( Span const & src );
		Span(size_t size);
		~Span();
		void	addNumber(int nb) throw (std::range_error);
		int		shortestSpan( void );
		int		longestSpan( void ) const;
		void	fillWithRandNums( void );
		void	printDebugInfo( void );

		Span &		operator=( Span const & rhs );

	private:
		size_t _max_size;
		std::vector <int> _elements;
		bool _sorted;
};

#endif /* ************************************************************ SPAN_H */