#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>() {};
		MutantStack(MutantStack<T> &other): std::stack<T>(other) {};
		~MutantStack() {};
		MutantStack &		operator=( MutantStack const &other )
		{
			this->c = other.c;
			return (*this);
		}
		typedef typename std::stack<T>::container_type::iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator iterator;

		iterator	begin( void ){ return (this->c.rbegin()); }
		iterator	end( void ){ return (this->c.rend()); }
		reverse_iterator	rbegin( void ){ return (this->c.begin()); }
		reverse_iterator	rend( void ){ return (this->c.end()); }
};

#endif